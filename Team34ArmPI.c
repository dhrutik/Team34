#pragma config(Sensor, in1,    pot,            sensorPotentiometer)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define TARGET 3675
//int potVal = 0;
task main()
{
	int error = 0;
	float pastError = 0;
	//int addNum = 0;
	while(true){
		error = TARGET - SensorValue[pot];
	//	addNum = -.001 * pastError;
		motor[port1] = -0.1 * error - .005 * pastError;
		pastError += error;
		wait1Msec(25);
		//potVal = SensorValue[pot];

	}


}