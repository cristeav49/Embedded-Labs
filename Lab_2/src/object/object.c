#include "object.h"

void ObjectInit(struct IO_Object *obj,
						uint8_t _pinNr,
						volatile uint8_t *_ddr,
						volatile uint8_t *_ioReg ) {
	obj->pinNr = _pinNr;
	obj->ddr = _ddr;
	obj->ioReg = _ioReg;
}

void setObjectDDR(struct IO_Object *obj) {
	*(obj->ddr) |= 1<<obj->pinNr;
}
