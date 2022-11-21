
#include <softTone.h>
#include "buzzer.h"

int initBuzzer(void)
{
#if 0
	//wiringpi Init	
	if(wiringPiSetupGpio() == -1) {
		return 1;
	}	
#endif

	// BUZZER Init
	pinMode(BUZZER_PIN, OUTPUT);		// BUZZER PIN OUTPUT SET	출력으로 설정
	digitalWrite(BUZZER_PIN, LOW);		// BUZZER OFF	출력 핀 0V 상태로 지정
	
	printf("Buzzer Initialize\n");

	softToneCreate (BUZZER_PIN) ;
	STOP_FREQ();
	return 0;
}	

void Change_FREQ(unsigned int freq)
{
	pwmWrite(BUZZER_PIN, freq);			
	softToneWrite (BUZZER_PIN, freq);
}

void STOP_FREQ (void)
{
	softToneWrite (BUZZER_PIN, 0);
}

void playBuzzer(unsigned char status)
{
	int i;
	if (status == 1) {
		digitalWrite(BUZZER_PIN, HIGH);		//BUZZER ON
		delay(10);
		digitalWrite(BUZZER_PIN, LOW);		//BUZZER OFF
		delay(10);
	}		
}
