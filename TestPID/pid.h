
/* ==========================================================================
; Title:  PID FOR ROBOCON 2020
; Author: Kuro - SPK FIRE-PHOENIX 
; Date:   12 Dec 2019
; Use for STM32
; ===========================================================================
*/

/* Desciption XOXO
			 _______________________
			 |			    
 in -------->| 
			 |
 			 |______________________

 */
#ifndef _PID_H_

#define  _PID_H_

//**********************************************/
#include <stdio.h>
//**********************************************/
#define FREQUENCY_UPDATE_PID	1000


typedef enum STATUSs {
	SUCCESS = 1,
	FAILED = - 1,
	UNKNOW = 0
}STATUS;

typedef struct PID_Factors {
	float kp; 							// (P)roportional
	float ki; 							// (I)ntegral
	float kd; 							// (D)erivative`
}PID_Factor;

STATUS PID_Factor__Init(PID_Factor* _myPIDFactor, float _kp, float _ki, float _kd); // use Init and Change Value
PID_Factor* PID_Factor__Create(float _kp,float _ki, float _kd);							
/*------------------------------MANUAL----------------------------------
User declar 2 ways: 
1)
PID_Factor* myPIDFactor = PID_Factor__Create(10, 20, 0.01);
2)
PID_Factor myPIDFactor;
PID_Factor__Init(&myPIDFactor, 10, 20, 0.01);

------------------------------------Have Fun--------------------------------
*/


typedef struct PIDs {
		// declare variable
		PID_Factor*  pidFactor;				// Kp Ki and Kd
		double* out; 						// this is address of output variable
		double* in; 						// this is address of input variable
		double * setPoint; 					// this is the value system want to achieve


		// this is private variable 
		double err;							// this is error = setpoint - current value(in)
		double sumErr;						// this is SUM of err use in integral
		//backup value
		double previousErr;					// this is previous err
}PID
;

// there are 2 way to create PID
STATUS PID__Init(PID* _myPID, PID_Factor* _myFactors,double* _in,double* _out,double* _setPoint);				// Init value PID
PID* PID__Create(PID_Factor* _myFactors, double* _in, double* _out, double* _setPoint);							// Create a new PID
//


// ---------------------------------------------------DEGUB FUNCTION ---------------------------------------------

void printClassPID(PID _myPID);
void printClassPID_Factor(PID_Factor _myFactors);

#endif // !_PID_H_
