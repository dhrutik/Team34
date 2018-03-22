#pragma config(Motor,  port2,           leftTop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightBottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftBottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightTop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           mogoRightLift, tmotorVex393_MC29, openLoop /*reverse*/)
#pragma config(Motor,  port7,           mogoLeftLift,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           coneRightLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           coneLeftLift,  tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void assignMotorSpeed (tMotor motor1, tMotor motor2, int speed){
	motor[motor1] = speed;
	motor[motor2] = speed;
}

bool btnNumMogo = false;
bool btnNumCone = false;
bool btnTap = false;
bool turnOnMotors = false;

task sustainMogo(){
	while(true){
		/*if(vexRT[Btn8U]){
		count = 1;
		}
		while(count%2 == 1){
		assignMotorSpeed(mogoRightLift,mogoLeftLift,50);
		count++;
		}*/
		if(vexRT[Btn8U]){
			if(!btnTap){ //not of false is true
				turnOnMotors = !turnOnMotors;
				btnTap = true;
			}
			else{
				btnTap = false;
				turnOnMotors = false;
			}
		}
		if(turnOnMotors){
			assignMotorSpeed(mogoRightLift,mogoLeftLift,50);
		}
		else{
			assignMotorSpeed(mogoRightLift,mogoLeftLift,0);
		}
	}
}

task main()
{//joks
	startTask(sustainMogo);
	while(true){
		/*motor[rightTop] = vexRT[Ch2];
		motor[rightBottom] = vexRT[Ch2];
		motor[leftTop] = vexRT[Ch3];
		motor[leftBottom] = vexRT[Ch3];*/
		int leftPower = vexRT(Ch3);
		if(abs(leftPower) < 20) {
			leftPower = 0;
		}
		int rightPower = vexRT(Ch2);
		if(abs(rightPower) < 20) {
			rightPower = 0;
		}
		assignMotorSpeed(rightTop,rightBottom,rightPower);
		assignMotorSpeed(leftTop,leftBottom,leftPower);

		assignMotorSpeed(mogoRightLift,mogoLeftLift,0);
		assignMotorSpeed(coneRightLift,coneLeftLift,0);

		switch(vexRT[btnNumMogo]){
		case Btn6U:
			assignMotorSpeed(mogoRightLift,mogoLeftLift,80);
			break;
		case Btn6D:
			assignMotorSpeed(mogoRightLift,mogoLeftLift,-80);
			break;
		/*case Btn8U:
			startTask(sustainMogo);*/
		default:
			assignMotorSpeed(mogoRightLift,mogoLeftLift,0);
		}

		switch(vexRT[btnNumCone]){
		case Btn5U:
			assignMotorSpeed(coneRightLift,coneLeftLift,90);
			break;
		case Btn5D:
			assignMotorSpeed(coneRightLift,coneLeftLift,-90);
			break;
		default:
			assignMotorSpeed(coneRightLift,coneLeftLift,0);
		}

		/*
		=======
		while(true){
		int leftPower = vexRT(Ch3);
		if(abs(leftPower) < 20) {
		leftPower = 0;
		}
		int rightPower = vexRT(Ch2);
		if(abs(rightPower) < 20) {
		rightPower = 0;
		}
		motor[leftTop] = leftPower;
		motor[leftBottom] = leftPower;
		motor[rightTop] = rightPower;
		motor[rightBottom] = rightPower;

		motor[mogoRightLift] = 0;
		motor[mogoLeftLift] = 0;
		motor[coneRightLift] = 0;
		motor[coneRightLift] = 0;

		if(vexRT[Btn6U]){
		motor[mogoRightLift] = 80;
		motor[mogoLeftLift] = 80;
		}
		else if(vexRT[Btn6D]){
		motor[mogoRightLift] = -80;
		motor[mogoLeftLift] = -80;
		}

		if(vexRT[Btn5U]){
		motor[coneRightLift] = 90;
		motor[coneLeftLift] = 90;
		}
		else if(vexRT[Btn5D]){
		motor[coneRightLift] = -90;
		motor[coneLeftLift] = -90;
		}
		if(vexRT[Btn8U]){
		motor[mogoRightLift] = 50;
		motor[mogoLeftLift] = 50;
		}
		else if(vexRT[Btn8R]){
		>>>>>>> 1a3f643c9f2e7ac46d7b7797b233ae1d37f3932c
		motor[mogoRightLift] = 0;
		motor[mogoRightLift] = 0;
		motor[mogoConeLift] = 0;
		motor[mogoConeLift] = 0;

		if(vexRT[Btn6U]){
		assignMotorSpeed(mogoRightLift,mogoLeftLift,80);
		}
		else if(vexRT[Btn6D]){
		assignMotorSpeed(mogoRightLift,mogoLeftLift,-80);
		}

		if(vexRT[Btn5U]){
		assignMotorSpeed(coneRightLift,coneLeftLift,90);
		}
		else if(vexRT[Btn5D]){
		assignMotorSpeed(coneRightLift,coneLeftLift,-90);
		}
		if(vexRT[Btn8U]){
		assignMotorSpeed(mogoRightLift,mogoLeftLift,50);
		}
		else if(vexRT[Btn8R]){
		assignMotorSpeed(mogoRightLift,mogoLeftLift,0);
		}
		if(vexRT[Btn7U]){
		assignMotorSpeed(coneRightLift,coneLeftLift,40);
		}
		else if(vexRT[Btn7L]){
		assignMotorSpeed(coneRightLift,coneLeftLift,0);
		}*/

	}

}
