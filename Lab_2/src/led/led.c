#include "led.h"

void LedOn(struct IO_Object *obj) {
	*(obj->ioReg) &= ~(1<< obj->pinNr);
}

void LedOff(struct IO_Object *obj) {
	*(obj->ioReg) |= (1<< obj->pinNr);
}
