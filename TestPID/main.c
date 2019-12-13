#include <stdio.h>
#include "pid.h"

void main() {
	double val = 10;
	double input = 0;
	double* output = &val;
	double setPoint = 100;
	PID_Factor* myPIDFactor = PID_Factor__Create(10, 20, 0.01);
	input = 2;

	PID* myPID = PID__Create(myPIDFactor, &input, output, &setPoint);
	input = 7;
	PID_Factor__Init(myPIDFactor,2,5,7);

	printClassPID(*myPID);

	system("pause");
}