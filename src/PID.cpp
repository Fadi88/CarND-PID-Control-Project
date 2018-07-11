#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  
  p_error = 0 ;
  d_error = 0 ;
  i_error = 0 ;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte; 
}

double PID::TotalError() {
  double ret = Kp*p_error + Kd*d_error + Ki*i_error;
  return ret > 1.0 ? 1.0 : (ret < -1.0 ? -1.0 : ret );
}

double PID::get_control_action() {

  return setpoint - TotalError();
}

void PID::set_setpoint(double target_setpoint){

  this->setpoint = target_setpoint;
}
