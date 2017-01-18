#ifndef USART_H
#define USART_H

#include <avr/io.h>

void USARTInit();
char USARTReadChar();
void USARTWriteChar(char data);

#endif