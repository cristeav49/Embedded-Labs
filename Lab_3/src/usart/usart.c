#include "usart.h"

void USARTInit() {
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=0x33;
}

char USARTReadChar() {
	
	while(!(UCSRA & (1<<RXC))) { }
	return UDR;
}

void USARTWriteChar(char data) {
	
	while(!(UCSRA & (1<<UDRE))) { }
	UDR=data;
}
