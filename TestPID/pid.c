#include  "pid.h"

STATUS PID_Factor__Init(PID_Factor * _myPIDFactor, float _kp, float _ki, float _kd)
{
	if (_myPIDFactor != NULL) {
		_myPIDFactor->kp = _kp;
		_myPIDFactor->ki = _ki;
		_myPIDFactor->kd = _kd;
		return SUCCESS;
	}
	else {
		return FAILED;
	}
	
}

PID_Factor * PID_Factor__Create(float _kp, float _ki, float _kd)
{
	PID_Factor* __result = (PID_Factor*)malloc(sizeof(PID_Factor));
	PID_Factor__Init(__result, _kp, _ki, _kd);
	return __result;
}

STATUS PID__Init(PID * _myPID, PID_Factor* _myFactors, double * _in, double * _out, double * _setPoint) {
	if(_myPID != NULL){
		_myPID->pidFactor = _myFactors;
		_myPID->in = _in;
		_myPID->out = _out;
		_myPID->setPoint = _setPoint;
		//setting private variable is 0
		_myPID->err = 0;
		_myPID->sumErr = 0;
		_myPID->previousErr = 0;
		//
		return SUCCESS;
	}
	else {
		return FAILED;
	}
}

PID * PID__Create(PID_Factor* _myFactors, double * _in, double * _out, double * _setPoint)
{

	PID* __result = (PID*)malloc(sizeof(PID));
	
	PID__Init(__result, _myFactors, _in, _out, _setPoint);

	return __result;
}

void printClassPID(PID  _myPID) {
	printf("%s\n", "-----------------------------------");
	printClassPID_Factor(*_myPID.pidFactor);
	printf("%s%f\n", "Value of [in] : ", *_myPID.in);
	printf("%s%f\n", "Value of [out] : ", *_myPID.out);
	printf("%s%f\n", "Value of [setpoint] : ", *_myPID.setPoint);
	printf("%s%f\n", "Value of [err] : ", _myPID.err);
	printf("%s%f\n", "Value of [sum of err] : ", _myPID.sumErr);
	printf("%s%f\n", "Value of [previous err] : ", _myPID.previousErr);
	
}

void printClassPID_Factor(PID_Factor  _myFactors) {
	printf("%s%f\n", "Value of [Kp] : ", _myFactors.kp);
	printf("%s%f\n", "Value of [Ki] : ", _myFactors.ki);
	printf("%s%f\n", "Value of [Kd] : ", _myFactors.kd);
}

