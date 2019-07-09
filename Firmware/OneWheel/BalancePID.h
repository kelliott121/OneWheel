#ifndef BALANCEPID_H
#define BALANCEPID_H
#include <Arduino.h>

class BalancePID {

  public:
    // Constructor - takes pointer inputs for control variables, so they are updated automatically
    BalancePID(double outputMin, double outputMax,
               double Kp, double Ki, double Kd);
    // Allows manual adjustment of gains
    void setGains(double Kp, double Ki, double Kd);
    // Allows manual readjustment of output range
    void setOutputRange(double outputMin, double outputMax);
    // Allows manual adjustment of time step (default 1000ms)
    void setTimeStep(unsigned long timeStep);
    // Returns true when at set point (+-threshold)
    bool atSetPoint(double threshold);
    // Runs PID calculations when needed. Should be called repeatedly in loop.
    // Automatically reads input and sets output via pointers
    double run(double input, double setpoint);
    // Stops PID functionality, output sets to 
    void stop();
    void reset();
    bool isStopped();

    double getIntegral();
    void setIntegral(double integral);
    void setIntegralLimit(double limit);

    double getOutP();
    double getOutI();
    double getOutD();

  private:
    double _Kp, _Ki, _Kd;
    double _Op, _Oi, _Od;
    double _output;
    double _integral, _integralLimit = 0;
    double _previousError;
    double _outputMin, _outputMax;
    unsigned long _timeStep, _lastStep;
    bool _stopped;

};

#endif
