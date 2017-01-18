#include "lm20.h"


void LM20_Init(void) {
	ADC_init();
}

unsigned int LM20_GetCelsiusValue(int value) {
	value = ADC_read(0x00);
	value = value * 500/1024;
	return value;
}

int convertToFarenheit(int value) {
	return((int) value *9/5 + 32);
}

int convertToKelvin(int value) {
	return value + 273;
}
