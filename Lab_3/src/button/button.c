#include "button.h"

char  isButtonPressed(struct Button *obj) {
	if((*(obj->ioReg))&(1<<obj->pinNr))
		return 1;
	return 0;
}

void setButtonDDR(struct Button *obj) {
	*(obj->ddr) |= 1<<obj->pinNr;
}

void initButton(struct Button *obj,
						uint8_t _pinNr,
						volatile uint8_t *_ddr,
						volatile uint8_t *_ioReg ) {
	obj->pinNr = _pinNr;
	obj->ddr = _ddr;
	obj->ioReg = _ioReg;
}
