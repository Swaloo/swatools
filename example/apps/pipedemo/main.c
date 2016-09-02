#include "swaloo.h"


	
static void
timeout_handler(void)
{
	uint8_t expired;
	//uint8_t data[3] = {1,2,3};
	uint8_t data[3];
	data[0] = 1;
	data[1] = 2;
	data[2] = 3;
	pipe_send(data,3);
	
	led_toggle(1);
	timer_reschedule(&expired, 0);
}

static void
pipe_rx_handler(uint8_t *packet, uint16_t packet_len, uint8_t channel_id)
{
	airlog("rx %d channel %d\n", packet_len, channel_id);
}

int main(void)
{
	pipe_rx_register(pipe_rx_handler);
	timer_register(500, timeout_handler);
	
	airlog("Helloworld \n");
	while(1)
	{
	}
	return 0;
}
