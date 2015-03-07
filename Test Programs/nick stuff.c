#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom)
#pragma config(Sensor, S3,     HTSMUX2,        sensorI2CCustom)
#pragma config(Motor,  motorA,          nxtA,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          nxtB,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          nxtC,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     lift,          tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    grabber1,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    grabber2,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    ballRelease,          tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "functions.h"
#include "gyroturn.h"
#include "lego-ultrasound.h"
#include "JoystickDriver.c"
#include "lego-touch.h"

#define touch  msensor_S2_3
#define side msensor_S2_1
#define forward msensor_S2_2
int turn;

byte Irangle;
int position;

void dumpUpTop(){
	while(USreadDist(forward) > 32) {
		motor[leftMotor] = 10;
		motor[rightMotor] = 10;
	}
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	servo[ballRelease]=255;
	nMotorEncoder[lift]=0;
	while(nMotorEncoder[lift]>-7132){
		motor[lift]=-100;
	}
	motor[lift]=0;
	servo[ballRelease]=0;
	sleep(2000);
	pivot(-90);
	drive(-50, 18);
	sleep(200);
	pivot(-70);
	drive(-100, 48);
	servo[ballRelease] = 255;
	sleep(500);
}


task main(){
	drive(50, 5);
	gyroturn(-90);
	drive(50, 24);
	gyroturn(90);
	drive(50, 24)
	gyroturn(90);
	readSensor(&irRight);
	readSensor(&irLeft);
	Irangle = irRight.acDirection;
	Irangle2 = irLeft.acDirection;
	if(Irangle==5 || Irangl2 == 7){
		drive(50, 5);
		dumpUpTop();
	}
	else {
		while(Irangle != 5 && Irangle !=7) {
			gyroTurn(1);
			readSensor(&irRight);
			readSensor(&irLeft);
			Irangle = irRight.acDirection;
			Irangle2 = irLeft.acDirection;
		}
	}