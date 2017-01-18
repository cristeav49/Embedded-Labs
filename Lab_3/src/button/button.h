#ifndef BUTTON_H_
#define BUTTON_H_


#include <stdint.h>
#include <avr/io.h>

struct Button {
	uint8_t pinNr;
	volatile uint8_t *ddr;
	volatile uint8_t *ioReg;
};

void initButton(struct Button *obj,
						uint8_t _pinNr,
						volatile uint8_t *_ddr,
						volatile uint8_t *_ioReg );

char isButtonPressed(struct Button *obj);
void setButtonDDR(struct Button *obj);

#endif
