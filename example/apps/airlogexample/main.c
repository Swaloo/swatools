#include "swaloo.h"

static void
timeout_handler(void)
{
	static i = 0;
	uint8_t expired;
	timer_reschedule(&expired, 0);
	airlog("AirLog debug example %d\n", i++);
}

int main(void)
{
	timer_register(1000, timeout_handler);
	while(1)
	{
		app_event_run();
	}
	return 0;
}
