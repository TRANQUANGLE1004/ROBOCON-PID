#include <stdio.h>
#include "pid.h"



void main() {
	double input = 1;  //sensor
	double output = 0;
	PID_FACTOR* myPIDFactor = PID_FACTOR__Create(1, 1, 0);
	PID* myPID = PID__Create(myPIDFactor, &input, &output, 100, (PID_OUT_LIMIT) { 0, 1000 });
	PID__OnOutputLimitFlag(myPID);

	printClassPID(*myPID);
	PID__Caculate(myPID);
	printClassPID(*myPID);
	PID__Caculate(myPID);
	printClassPID(*myPID);
	/*printf("%f", output);*/
	system("pause");
}