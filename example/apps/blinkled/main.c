#include "swaloo.h"

static void
timeout_handler(void)
{
	uint8_t expired;
	led_toggle(1);
	led_toggle(0);
	led_toggle(2);
	timer_reschedule(&expired, 0);
}

int main(void)
{
	timer_register(500, timeout_handler);
	while(1)
	{
	}
	return 0;
}
