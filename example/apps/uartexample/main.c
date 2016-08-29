#include "swaloo.h"

void rx_handler(uint8_t data)
{	
	// echo
	uint8_t echo[4] = {1,2,3,data};
	uart_send(echo, 4);
}

int main(void)
{
	uint8_t data[8] = {1,2,3,4,5,6,7,8};
	uart_port_t port;
	port.tx = 9;
	port.rx = 11;
	port.baudrate = UART_BAUDRATE_38400;
	
	uart_register(&port, rx_handler);
	uart_send(data, 8);
	while(1) {
	}
	return 0;
}
