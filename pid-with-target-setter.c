#pragma config(Sensor, in1,    pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl1,  controllerSensor, sensorQuadEncoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#define KP -0.1
#define KI 0.008

task main() {

int target = 3675;

int iCap = 1200;

int error = 0;
int iAccumulator = 0;

	while(true) {
		// update the past error
		error = (target - SensorValue[pot]);
		iAccumulator += error;
		// cap the I
		if(iAccumulator > iCap) iAccumulator = iCap;
		if(iAccumulator < -1 * iCap) iAccumulator = -iCap;
		motor[port1] = KP * error - KI * iAccumulator;
		delay(25);
	}
}
