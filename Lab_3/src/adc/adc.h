#ifndef ADC_H
#define ADC_H

#define ADC_VREF_TYPE 0x40

#include <avr/delay.h>
#include <avr/io.h>

void ADC_init(void);
unsigned int ADC_read(unsigned char adc_input);

#endif	




