#include "swaloo.h"

static void 
accel_data_event_handler(accel_raw_data_t *data)
{
	syslog("time:%u x: %d y: %d z:%d\n", 
				data->timestamp,
				data->x, data->y, data->z);
}

int main(void)
{
	accel_data_register(accel_data_event_handler);
	while(1)
	{
	}
	return 0;
}
