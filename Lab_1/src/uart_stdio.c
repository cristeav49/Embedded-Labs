#include "uart_stdio.h"
FILE uart_istream = FDEV_SETUP_STREAM(uart_PutChar, NULL, _FDEV_SETUP_WRITE);

void uart_stdio_Init(void)
{
	stdout = &uart_istream;

	#if F_CPU < 2000000UL && defined(U2X)
	  UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	  UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	  UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	  UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */
}

int uart_PutChar(char c, FILE *stream)
{
	if (c == '\n')
		uart_PutChar('\r', stream);
	
	while (~UCSRA & (1 << UDRE));
	UDR = c;


	return 0;
}

