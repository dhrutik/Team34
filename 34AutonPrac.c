<<<<<<< HEAD
#pragma config(Sensor, in5,    mogoLift,       sensorPotentiometer)
#pragma config(Sensor, in7,    coneLift,       sensorPotentiometer)
#pragma config(Sensor, dgtl2,  drive,          sensorQuadEncoder)
#pragma config(Motor,  port1,           rightTop,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightBottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftTop,       tmotorVex393_MC29, openLoop)
=======














#pragma config(Sensor, in1,    coneLift,       sensorPotentiometer)
#pragma config(Sensor, in2,    mogoLift,       sensorPotentiometer)
#pragma config(Sensor, dgtl1,  drive,          sensorQuadEncoder)
#pragma config(Motor,  port2,           leftTop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightBottom,   tmotorVex393_MC29, openLoop, reversed)
>>>>>>> 975e18e3ef3d20d7117ab9d1f164401b5f319266
#pragma config(Motor,  port4,           leftBottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightTop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           mogoRightLift, tmotorVex393_MC29, openLoop /*reverse*/)
#pragma config(Motor,  port7,           mogoLeftLift,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           coneRightLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           coneLeftLift,  tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float distToMogo = 1500;
float distTo10Zone = -1500;
float currDist = SensorValue[drive];
//float distTo20Zone = 0;
//float encoderVal = 0;
int targetMogoLiftUp = 0;
int targetMogoLiftDown = 0;
float conePotVal = 0; //to be determined from testing or other groups
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
/*void turnAround(){
int turnTarget = SensorValue[drive] + (360*(11.25/4));
int error = turnTarget - SensorValue[drive];
motor[leftBottom] = 0.1 * error;
motor[leftTop] = 0.1 * error;
}
*/
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
			wait1Msec(10);
		}
		turnOffDriveMotors();
		wait1Msec(10);
		/*
POT BASED (MOGO) AUTON
		while(SensorValue[mogoLift] < targetMogoLiftUp){
		liftMogoUp();
		wait1Msec(10);
		}
			keepMogoUp();
		while(SensorValue[mogoLift] > targetMogoLiftDown){
			bringMogoDown();
		} */

// TIME BASED (MOGO) AUTON
		for(int i = 2; i>0; i--){
			wait10Msec(i*10);
			liftMogoUp();
		}
		keepMogoUp();
		/*
		* If turning after picking up mogo
		* turnAround();
		* Adjust value of 'distTo10Zone' if we can't do a turn in place
		*/
		while(SensorValue[drive] < /*>*/ distTo10Zone){ // value can be changed to suit 20 point zone
			reverseDriveMotors();
			wait1Msec(10);
		}
<<<<<<< HEAD

=======
>>>>>>> 975e18e3ef3d20d7117ab9d1f164401b5f319266
		/*
		* If turning after returning to point zone
		* turnAround();
		* Might have to go foreward a little
		*/
		for(int i = 2; i>0; i--){
			wait10Msec(i*10);
			bringMogoDown();
		}


	}

}



task main()
{
	startTask(auton1);
}
