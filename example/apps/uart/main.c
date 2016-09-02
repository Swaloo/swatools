#include "swaloo.h"

static void
uart_rx_handler(uint8_t data)
{
	airlog("recv %d\n",data);
}

int main(void)
{
	uart_port_t port;
	port.tx = 9;
	port.rx = 11;
	port.baudrate = UART_BAUDRATE_38400;
	uart_register(&port, uart_rx_handler);
	while(1)
	{
	}
	return 0;
}
