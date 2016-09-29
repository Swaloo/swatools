/*
* Copyright (C) 2016 AlfaLoop Technology Co., Ltd.
*
* Licensed under the Apache License, Version 2.0 (the "License";
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* 	  www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef __SWALOO_H_
#define __SWALOO_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


// Core Service
typedef void (* battery_stage_changed_handler_t)(uint8_t percent, uint8_t is_charging);
int core_devid_id(uint8_t *id, int max_len);
int battery_stage_register(battery_stage_changed_handler_t handler);
int battery_stage_unregister(void);

// APP Event pool
void app_event_run(void);

// Time Service
void delay_ms(int millis);

// BLE Service
#define BLE_ADDRESS_LEN           	6
#define ADV_MAX_DATA_SIZE           31				// Maximum size of advertising data in octets.
typedef struct {
	uint8_t   peer_address[BLE_ADDRESS_LEN];      	 	 	// Bluetooth address of the peer device.
	uint8_t   data[ADV_MAX_DATA_SIZE];    // Advertising or scan response data.
	uint8_t   len;          	  	   			// Advertising or scan response data length.
	uint8_t	  scan_response;
	uint8_t   type;
	int8_t    rssi;                  			// Received Signal Strength Indication in dBm.
} ble_observer_report_t;

typedef struct {
	uint8_t	 active;
	uint32_t interval;
	uint16_t window;
} ble_observer_params_t;

typedef struct {
	uint32_t min_conn_interval;
	uint32_t max_conn_interval;
	uint16_t window;
} ble_central_conn_params_t;
typedef void (* ble_observer_handler_t)(ble_observer_report_t *report);
int ble_observer_register(ble_observer_handler_t *handler);
int ble_observer_unregister(void);
int ble_observer_start(ble_observer_params_t *params);
int ble_observer_stop(void);

// Uart Service
enum {
	UART_BAUDRATE_1200 ,
    UART_BAUDRATE_2400 ,
    UART_BAUDRATE_4800 ,
    UART_BAUDRATE_9600 ,
    UART_BAUDRATE_19200 ,
    UART_BAUDRATE_38400 ,
    UART_BAUDRATE_57600 ,
    UART_BAUDRATE_115200,
};
typedef void (* uart_rx_handler_t)(uint8_t data);
typedef struct{
    uint32_t tx;
    uint32_t rx;
    uint32_t baudrate;
} uart_port_t;
int uart_register(uart_port_t *port, uart_rx_handler_t handler);
int uart_send(uint8_t *data, uint32_t length);

// GPIO Services
#define GPIO_INPUT  			0x00
#define GPIO_INPUT_PULLUP		0x01
#define GPIO_INPUT_PULLDOWN		0x02

#define GPIO_LOW  				0x00
#define GPIO_HIGH  				0x01

int gpio_cfg_output(uint32_t pin, uint8_t high);
int gpio_cfg_input(uint32_t pin, uint8_t pull);

// Pipe Services
typedef void (* pipe_rx_handler_t)(uint8_t *packet, uint16_t packet_len, uint8_t channel_id);
int pipe_tx_with_channel(uint8_t *packet, uint16_t packet_len, uint8_t channel_id);
int pipe_tx(uint8_t *packet, uint16_t packet_len);
int pipe_rx_register(pipe_rx_handler_t handler);
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

typedef void (* accel_data_handler_t)(accel_raw_data_t *data);

int accel_cfg_sampling_rate(uint32_t rate);
int accel_cfg_scale_range(uint32_t scale);
int accel_data_register(accel_data_handler_t handler);
int accel_data_unregister(void);

// Timer Services
typedef void (* timer_timeout_handler_t)(void);
int timer_register(uint32_t timeout_ms, timer_timeout_handler_t handler);
int timer_reschedule(uint8_t *expired, uint32_t new_timeout_ms);
int timer_unregister(void);

// Led Services
int led_on(uint32_t led);
int led_off(uint32_t led);
int led_toggle(uint32_t led);
int led_status(uint32_t led, uint8_t *status);
int led_total_num(uint8_t *num);

#ifdef __cplusplus
}
#endif
#endif /* __SWALOO_H_ */
