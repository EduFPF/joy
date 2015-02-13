// 2-axis Differential.ino
/*
	Universidade Federal de Campina Grande
	Eduardo Figueiredo Porto Filho
	Engenharia Elétrica
	e-Robótica
*/

//sensorReading.endsWith(0)

#include <AFMotor.h>

//Inicialização de variáveis
char pwm[3];
int incPwm = 0, val = 0, modVal = 0;
AF_DCMotor motorE(1);
AF_DCMotor motorD(2);

void setup() {
	Serial.begin(9600);

	motorE.setSpeed(0);
  	motorE.run(RELEASE);

  	motorD.setSpeed(0);
  	motorD.run(RELEASE);

}

void loop() {
	if (Serial.available() >= 4) {
		while (Serial.available() <= 4) { //ver isso ae
			pwm[incPwm] = Serial.read();
			incPwm++;
		}
	}

	incPwm = 0;

	val = pwm[0] + pwm[1]*10 + pwm[2]*100;
	modVal = |val|;

	if (pwm[3] == 'x') {
		if (val < 0)
			//Left
			motorE.setSpeed(modVal);
  			motorE.run(BACKWARD);

  			motorD.setSpeed(modVal);
  			motorD.run(FORWARD);

		else if (val >= 0)
			//Right
			motorE.setSpeed(modVal);
  			motorE.run(FORWARD);

  			motorD.setSpeed(modVal);
  			motorD.run(BACKWARD);
	}
	else if (pwm[3] == 'y'){
		if (val < 0)
			//Backward
			motorE.setSpeed(modVal);
  			motorE.run(BACKWARD);

  			motorD.setSpeed(modVal);
  			motorD.run(BACKWARD);
		else if (val >= 0)
			//Forward
			motorE.setSpeed(modVal);
  			motorE.run(FORWARD);

  			motorD.setSpeed(modVal);
  			motorD.run(FORWARD);

	}

}