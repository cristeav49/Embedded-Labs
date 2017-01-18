#include "button.h"

char  isButtonPressed(struct IO_Object *obj) {
	if((*(obj->ioReg))&(1<<obj->pinNr))
		return 1;
	return 0;
}
