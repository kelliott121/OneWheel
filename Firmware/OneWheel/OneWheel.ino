#include <EEPROM.h>

//#include <Ethernet.h>

//#include <PulsePosition.h>
#include <Servo.h>

#include <Adafruit_BNO055.h>
#include "BalancePID.h"

#include "../../../Shared/Data.h"

// Set the delay between fresh samples
#define BNO055_SAMPLERATE_DELAY_MS (100)
static const int KP_OFFSET     = 0 * sizeof(double);
static const int KI_OFFSET     = 1 * sizeof(double);
static const int KD_OFFSET     = 2 * sizeof(double);
static const int CENTER_OFFSET = 3 * sizeof(double);

struct LoopTimer_t
{
  unsigned long start;
  unsigned long end;
  unsigned long delta;
};

volatile LoopTimer_t ControlLoopTimer;
volatile LoopTimer_t IdleLoopTimer;

Adafruit_BNO055 bno = Adafruit_BNO055(55);

// Initialize PID controller
static const double MIN_OUT = -500;
static const double MAX_OUT = 500;
double KP = 0;
double KI = 0;
double KD = 0;
volatile double Angle = 0, SetPoint = 0, Output = 0;
BalancePID controller(MIN_OUT, MAX_OUT, KP, KI, KD);

//PulsePositionOutput ControlOut;
Servo ControlOut;

IntervalTimer ControlInterruptTimer;

volatile int MidOffset = 0;
volatile bool ClosedLoop = false;
volatile int OverrideCommand = 0;

volatile SharedData_t SharedData;

void ProcessSerial();
void ProcessGain(String serialCommand);
void SaveGains();
void ProcessLoop(String serialCommand);
void ProcessCommand(String serialCommand);
void ProcessOffset(String serialCommand);
void SaveOffset();
void ControlLoop();

void ProcessSerial()
{
  while (Serial.available())
  {
    String serialCommand = Serial.readStringUntil('\n');

    if (serialCommand.startsWith("setgain"))
    {
      ProcessGain(serialCommand.replace("setgain ", ""));
    }
    else if (serialCommand.startsWith("savegains"))
    {
      SaveGains();
    }
    else if (serialCommand.startsWith("setloop"))
    {
      ProcessLoop(serialCommand.replace("setloop ", ""));
    }
    else if (serialCommand.startsWith("setcommand"))
    {
      ProcessCommand(serialCommand.replace("setcommand ", ""));
    }
    else if (serialCommand.startsWith("setoffset"))
    {
      ProcessOffset(serialCommand.replace("setoffset ", ""));
    }
    else if (serialCommand.startsWith("saveoffset"))
    {
      SaveOffset();
    }
  }
}

void ProcessGain(String serialCommand)
{
  if (serialCommand.startsWith("p"))
  {
    serialCommand.replace("p ", "");
    KP = (double)serialCommand.toFloat();
  }
  else if (serialCommand.startsWith("i"))
  {
    serialCommand.replace("i ", "");
    KI = (double)serialCommand.toFloat();
  }
  else if (serialCommand.startsWith("d"))
  {
    serialCommand.replace("d ", "");
    KD = (double)serialCommand.toFloat();
  }

  Serial.print("Setting gains to: ");
  Serial.print("KP:");
  Serial.print(KP);
  Serial.print(" KI:");
  Serial.print(KI);
  Serial.print(" KD:");
  Serial.println(KD);
  controller.setGains(KP, KI, KD);
}

void SaveGains()
{
  EEPROM.put(KP, KP_OFFSET);
  EEPROM.put(KI, KI_OFFSET);
  EEPROM.put(KD, KD_OFFSET);
  //EEPROM.update();
}

void ProcessLoop(String serialCommand)
{
  if (serialCommand.startsWith("open"))
  {
    Serial.println("Entering Open Loop");
    ClosedLoop = false;
  }
  else if (serialCommand.startsWith("closed"))
  {
    Serial.println("Entering Closed Loop");
    ClosedLoop = true;
  }
}

void ProcessCommand(String serialCommand)
{
  Serial.print("Setting command to ");
  OverrideCommand = serialCommand.toInt();
  Serial.println(OverrideCommand);
}

void ProcessOffset(String serialCommand)
{
  Serial.print("Setting Offset to ");
  MidOffset = serialCommand.toInt();
  Serial.println(MidOffset);
}

void SaveOffset()
{
  EEPROM.put(MidOffset, CENTER_OFFSET);
  //EEPROM.update();
}

void setup()
{
  Serial.begin(115200);
  
  // Initialise the sensor
  if(!bno.begin())
  {
    // There was a problem detecting the BNO055 ... check your connections
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  // Use external crystal for better accuracy
  bno.setExtCrystalUse(true);

  controller.setTimeStep(LOOP_TIME_MS);
  controller.setIntegralLimit(500);
  ControlOut.attach(5, 500, 2500);
  ControlOut.writeMicroseconds(1500);

  ControlInterruptTimer.begin(ControlLoop, LOOP_TIME_MS * 1000);
}

void loop()
{
  static uint64_t LastUpdate = 0;
  // Start the Loop timer
  IdleLoopTimer.start = micros();
  
  ProcessSerial();

  noInterrupts();
  SharedData.angle = (volatile double)Angle;
  SharedData.output.p = controller.getOutP();
  SharedData.output.i = controller.getOutI();
  SharedData.output.d = controller.getOutD();
  SharedData.idleLoopTimer = IdleLoopTimer.delta;
  SharedData.controlLoopTimer = ControlLoopTimer.delta;
  interrupts();

  if ((millis() - LastUpdate) > UPDATE_TIME_MS)
  {
    Serial.println(Angle);
  
    Serial.write('p');
    Serial.write(':');
    Serial.write((byte*)&SharedData, sizeof(SharedData));
    Serial.write('\n');

    LastUpdate = millis();
  }
  
  IdleLoopTimer.end = micros();
  IdleLoopTimer.delta = IdleLoopTimer.end - IdleLoopTimer.start;
}

void ControlLoop()
{
  //noInterrupts();
  
  ControlLoopTimer.start = micros();
  //Serial.println("Entering Control Loop");
  // Fetch the gravity vector and determine the to the ground
  imu::Vector<3> gravity = bno.getVector(Adafruit_BNO055::VECTOR_GRAVITY);
  
  auto retrievedAngle = degrees(atan(gravity.x()/gravity.z()));
  // Only update the angle if it is not NaN
  if (!isnan(retrievedAngle))
  {
    Angle = retrievedAngle;
  }

  Output = controller.run(Angle, 0);

  if (ClosedLoop)
  {
    ControlOut.writeMicroseconds(1500 + Output - 50 + MidOffset);
  }
  else
  {
    ControlOut.writeMicroseconds(1500 + OverrideCommand - 50 + MidOffset);
  }

  ControlLoopTimer.end = micros();
  ControlLoopTimer.delta = ControlLoopTimer.end - ControlLoopTimer.start;
  //interrupts();
}

