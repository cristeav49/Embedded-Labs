
#include <avr/delay.h>
#include "lcd/lcd_hd44780_avr.h"
#include "usart/usart.h"
#define ADC_VREF_TYPE 0x40

void ADC_init(void) // Initialization of ADC
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);    // faktor pembagi 128
}

unsigned int ADC_read(unsigned char adc_input)
{
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



int main(void)
{
	uint16_t adc_result0;
	int temp;
	unsigned int value;
	char buffer[10];
	char snum[5];
	USARTInit();
	ADC_init();
	//LCDGotoXY(0,0);
	LCDInit(LS_BLINK);
    while(1)
    {
		value=ADC_read(0x00);
		value=value*500/1024;
		// convert 123 to string [buf]
		itoa(value, buffer, 10);
		//sprintf(buffer,"Temp=",value);
		//printf("Kelvin : %d\n",value);
        

        LCDWriteString(buffer);
		
		_delay_ms(50);
		LCDGotoXY(0,0);
    }
}