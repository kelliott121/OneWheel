#include "BalancePID.h"

BalancePID::BalancePID(double outputMin, double outputMax,double Kp, double Ki, double Kd)
 {
  _outputMin = outputMin;
  _outputMax = outputMax;
  setGains(Kp, Ki, Kd);
  _timeStep = 1000;
}

void BalancePID::setGains(double Kp, double Ki, double Kd) {
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

void BalancePID::setOutputRange(double outputMin, double outputMax) {
  _outputMin = outputMin;
  _outputMax = outputMax;
}

void BalancePID::setTimeStep(unsigned long timeStep){
  _timeStep = timeStep;
}

double BalancePID::run(double input, double setpoint) {
  if (_stopped) {
    _stopped = false;
    reset();
    return 0;
  }

  unsigned long _dT = millis() - _lastStep;   //calculate time since last update
  if (_dT >= _timeStep)
  {                     //if long enough, do PID calculations
    _lastStep = millis();
    double _error = setpoint - input;
    _integral += (_error + _previousError) / 2 * _dT / 1000.0;   //Riemann sum integral
    if (_integralLimit != 0)
    {
      _integral = constrain(_integral, -_integralLimit, _integralLimit);
    }
    double _dError = (_error - _previousError) / _dT / 1000.0;   //derivative
    _previousError = _error;
    _Op = (_Kp * _error);
    _Oi = (_Ki * _integral);
    _Od = (_Kd * _dError);
    double PID = _Op + _Oi + _Od;
    _output = constrain(PID, _outputMin, _outputMax);
    return _output;
  }
  else
  {
    return _output;
  }
}

void BalancePID::stop() {
  _stopped = true;
  reset();
}
void BalancePID::reset() {
  _lastStep = millis();
  _integral = 0;
  _previousError = 0;
}

bool BalancePID::isStopped(){
  return _stopped;
}

double BalancePID::getIntegral(){
  return _integral;
}

void BalancePID::setIntegral(double integral){
  _integral = integral;
}

void BalancePID::setIntegralLimit(double limit)
{
  _integralLimit = limit;
}

double BalancePID::getOutP()
{
  return _Op;
}

double BalancePID::getOutI()
{
  return _Oi;
}

double BalancePID::getOutD()
{
  return _Od;
}


