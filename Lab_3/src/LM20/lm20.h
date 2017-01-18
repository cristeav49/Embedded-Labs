#ifndef LM20_H
#define LM20_H

void LM20_Init(void);

unsigned int LM20_GetCelsiusValue(int value);
int convertToKelvin(int value);
int convertToFarenheit(int value);

#endif