#pragma config(Sensor, in1,    coneLift,       sensorPotentiometer)
#pragma config(Sensor, in2,    mogoLift,       sensorPotentiometer)
#pragma config(Sensor, dgtl1,  drive,          sensorQuadEncoder)
#pragma config(Motor,  port1,           rightTop,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightBottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftTop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftBottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           mogoRightLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           mogoLeftLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           coneRightLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           coneLeftLift,  tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float distToMogo = 0;
float distTo10Zone = 0;
//float distTo20Zone = 0;
//float encoderVal = 0;
int targetMogoLiftUp = 0;
int targetMogoLiftDown = 0;
float conePotVal = 0;
// for PID if necessary
int targetConeLiftUp = 0;
int targetConeLiftDown = 0;
//int targetDrive = 0;

// .8*127 = 101.6 ~~ 102
void turnOnDriveMotors(){
	motor[rightTop] = 102;
	motor[rightBottom] = 102;
	motor[leftTop] = 102;
	motor[leftBottom] = 102;
}
void turnOffDriveMotors(){
	motor[rightTop] = 0;
	motor[rightBottom] = 0;
	motor[leftTop] = 0;
	motor[leftBottom] = 0;
}
void reverseDriveMotors(){
	motor[rightTop] = -102;
	motor[rightBottom] = -102;
	motor[leftTop] = -102;
	motor[leftBottom] = -102;

}
void liftMogoUp(){
	motor[mogoRightLift] = 102;
	motor[mogoLeftLift] = 102;
}
/*void stopMogoMotors(){
motor[mogoRightLift] = 0;
motor[mogoLeftLift] = 0;
}*/
void keepMogoUp(){
	motor[mogoRightLift] = 70;
	motor[mogoLeftLift] = 70;
}
void bringMogoDown(){
	motor[mogoRightLift] = -102;
	motor[mogoLeftLift] = -102;
}
void stackConeOnMogo(){

}

task auton1()
{
	/*
	* AUTON TO 10PT ZONE
	* drive to encoder target value (where mogo is)
	* stop motors
	* pick up mogo (lift mogo pot val)
	* sustain mogo
	* reverse motors
	* go back to starting/10pt-zone (use second encoder val)
	* lower mogo (lower mogo pot val// second?)
	*/
	while(true){
		while(SensorValue[drive] < distToMogo){
			turnOnDriveMotors();
			wait10Msec(1);
		}
		turnOffDriveMotors();
		wait10Msec(1);
		while(SensorValue[mogoLift] < targetMogoLiftUp){
			liftMogoUp();
			wait10Msec(1);
		}
		keepMogoUp();
		while(SensorValue[drive] < /*>*/ distTo10Zone){ // value can be changed to suit 20 point zone
			reverseDriveMotors();
			wait10Msec(1);
		}
		while(SensorValue[mogoLift] < /*>*/ targetMogoLiftDown){
			bringMogoDown();
		}

	}

}

task auton2()
{
	/*
	* AUTON TO STACK CONE ON MOGO THEN GO
	*/

}


task main()
{
	startTask(auton1);
	startTask(auton2);
}
