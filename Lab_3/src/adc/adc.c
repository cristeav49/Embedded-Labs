#include "adc.h"

void ADC_init(void) {

	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);    
}	

unsigned int ADC_read(unsigned char adc_input) {
	ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	// Delay needed for the stabilization of the ADC input voltage
	_delay_us(10);
	// Start the AD conversion
	ADCSRA|=0b01000000;
	// Wait for the AD conversion to complete
	while ((ADCSRA & 0x10)==1);
	ADCSRA|=0b00000;
	return ADCW;
}