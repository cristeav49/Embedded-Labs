#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdint.h>
#include <avr/io.h>

struct IO_Object {
	uint8_t pinNr;
	volatile uint8_t *ddr;
	volatile uint8_t *ioReg;
};

void ObjectInit(struct IO_Object *obj,
						uint8_t _pinNr,
						volatile uint8_t *_ddr,
						volatile uint8_t *_ioReg 
						);

void setObjectDDRHigh(struct IO_Object *obj);
void setObjectDDRLow(struct IO_Object *obj);

#endif

