/**
 *  Copyright (c) 2016 AlfaLoop Technology Co., Ltd. All Rights Reserved.
 *
 *  Unauthorized copying of this file, via any medium is strictly prohibited
 *  Proprietary and confidential.
 *
 *  Attribution ¡X You must give appropriate credit, provide a link to the license, and
 *  indicate if changes were made. You may do so in any reasonable manner, but not in any 
 *  way that suggests the licensor endorses you or your use.
 *
 *  NonCommercial ¡X You may not use the material for commercial purposes under unauthorized.
 *
 *  NoDerivatives ¡X If you remix, transform, or build upon the material, you may not 
 *  distribute the modified material.
 */
#ifndef __SWALOO_AK2DK_H_
#define __SWALOO_AK2DK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Pipe Services
typedef void (* pipe_rx_handler)(uint8_t *packet, uint16_t packet_len, uint8_t channel_id);
int pipe_tx_with_channel(uint8_t *packet, uint16_t packet_len, uint8_t channel_id);
int pipe_tx(uint8_t *packet, uint16_t packet_len);
int pipe_rx_register(pipe_rx_handler handler);
int pipe_rx_unregister(void);
int airlog(const char *fmt, ...);

// Accel Sensor Services
#define ACCEL_SAMPLING_10HZ	 		0x00
#define ACCEL_SAMPLING_20HZ	 		0x01
#define ACCEL_SAMPLING_50HZ	 		0x02
#define ACCEL_SAMPLING_100HZ	 	0x03

#define ACCEL_FULL_SCALE_RANGE_2G	 	0x00
#define ACCEL_FULL_SCALE_RANGE_4G	 	0x01
#define ACCEL_FULL_SCALE_RANGE_8G	 	0x02
#define ACCEL_FULL_SCALE_RANGE_16G	 	0x03

typedef struct accel_raw_data {
	int16_t x;
	int16_t y;
	int16_t z;
	uint32_t timestamp;
} accel_raw_data_t;

typedef void (* accel_data_handler)(accel_raw_data_t *data);

int accel_cfg_sampling_rate(uint32_t rate);
int accel_cfg_scale_range(uint32_t scale);
int accel_data_register(accel_data_handler handler);
int accel_data_unregister(void);

// Timer Services
typedef void (* timer_timeout_handler)(void);
int timer_register(uint32_t timeout_ms, timer_timeout_handler handler);
int timer_reschedule(uint8_t *expired, uint32_t new_timeout_ms);
int timer_cancel(void);

// Led Services
int led_on(uint32_t led);
int led_off(uint32_t led);
int led_toggle(uint32_t led);
int led_status(uint32_t led, uint8_t *status);
int led_total_num(uint8_t *num);

int syslog(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* __SWALOO_AK2DK_H_ */
