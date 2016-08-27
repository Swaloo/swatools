#include "swaloo.h"

static void 
pipe_data_event_handler(uint8_t *packet, uint16_t packet_len, uint8_t channel_id)
{
	syslog("pipe event channel %d\n", channel_id);
	for (uint8_t i = 0; i < packet_len; i++) {
		syslog("%2x ", packet[i]);
	}
	syslog("\n");
}

static void
timeout_handler(void)
{
	uint8_t data[8] = {1,2,3,4,5,6,7,8};
	uint8_t expired;
	pipe_tx(data, 8);
	timer_reschedule(&expired, 0);
}

int main(void)
{
	pipe_rx_register(pipe_data_event_handler);
	timer_register(2000, timeout_handler);
	while(1)
	{
	}
	return 0;
}
