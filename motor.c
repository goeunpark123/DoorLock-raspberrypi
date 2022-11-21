#include "motor.h"

int initMotor(void)
{
#if 0
	if (wiringPiSetupGpio() == -1)
		return 1;
#endif
	printf("Motor Initialize.\n");
	pinMode(MOTOR_LEFT_ROTATE_PIN, OUTPUT);		//왼쪽 회전 PIN 출력으로 설정
	pinMode(MOTOR_RIGHT_ROTATE_PIN, OUTPUT);	//오른쪽 회전 PIN 출력으로 설정

	softPwmCreate(MOTOR_LEFT_ROTATE_PIN, 0, 100);		//pwm 범위: 0부터 100
	softPwmCreate(MOTOR_RIGHT_ROTATE_PIN, 0, 100);
	
	return 0;
}	

void MotorStop()
{
	softPwmWrite(MOTOR_LEFT_ROTATE_PIN, 0);
	softPwmWrite(MOTOR_RIGHT_ROTATE_PIN, 0);
}

void MotorControl(unsigned char speed, unsigned char rotate)
{
	if(rotate == LEFT_ROTATE) {
		digitalWrite(MOTOR_RIGHT_ROTATE_PIN, LOW);
		softPwmWrite(MOTOR_LEFT_ROTATE_PIN, speed);		//왼쪽 회전 PIN 원하는 속도로 출력
	}
	else if(rotate == RIGHT_ROTATE) {
		digitalWrite(MOTOR_LEFT_ROTATE_PIN, LOW);
		softPwmWrite(MOTOR_RIGHT_ROTATE_PIN, speed);		//오른쪽 회전 PIN 원하는 속도로 출력
	}
}

