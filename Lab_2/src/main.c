#include <avr/delay.h>
#include "led/led.h"
#include "button/button.h"
#include "lcd/lcd_hd44780_avr.h"

struct IO_Object btn;
struct IO_Object led;

void initObjects(void);
void enableObjects(void);

int main(void) {
	
	initObjects();
	LCDInit(LS_BLINK);
	
	while (1) {
		
		LCDClear();
		LCDHome();
		
		enableObjects();
		
		_delay_ms(100);
	}
}

void initObjects(void) {
	ObjectInit(&btn, PINC5, &DDRC, &PINC);
	setObjectDDR(&btn);
	
	ObjectInit(&led, PINC6, &DDRC, &PORTC);
	setObjectDDR(&led);
}

void enableObjects(void) {
	if(isButtonPressed(&btn)) {
		LedOn(&led);
		LCDWriteString("Embedded");
	} else {
		LedOff(&led);
		LCDWriteString("OFF");
	}
}
