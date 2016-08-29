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
#ifndef __SWALOO_H_
#define __SWALOO_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Scanner Service
#define ADV_MAX_DATA_SIZE           31			// Maximum size of advertising data in octets.
#define ADV_TYPE_ADV_IND          	0x00  	    // Connectable undirected.
#define ADV_TYPE_ADV_DIRECT_IND   	0x01   		// Connectable directed.
#define ADV_TYPE_ADV_SCAN_IND     	0x02   		// Scannable undirected.
#define ADV_TYPE_ADV_NONCONN_IND  	0x03   		// Non connectable undirected.
typedef struct {
	uint8_t 	peer_address[6];      	 	 	// Bluetooth address of the peer device.
	uint8_t     data[ADV_MAX_DATA_SIZE];    	// Advertising or scan response data.
	uint8_t     len;          	  	   			// Advertising or scan response data length.
	int8_t      rssi;                  			// Received Signal Strength Indication in dBm.
} scanner_report_t;
typedef struct {
	uint8_t	 active;
	uint32_t interval;
	uint16_t window;
} scanner_params_t;
typedef void (* scanner_handler_t)(scanner_report_t *report, uint8_t scan_rsp, uint8_t type);
int scanner_register(scanner_params_t *params, scanner_handler_t handler);
int scanner_unregister(void);

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
typedef void (* uart_rx_handler)(uint8_t data);
typedef struct{
    uint32_t tx;          
    uint32_t rx;        
    uint32_t baudrate;   
} uart_port_t;
int uart_register(uart_port_t *port, uart_rx_handler handler);
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

// Airlog Services
int airlog(const char *fmt, ...);


#ifdef __cplusplus
}
#endif
#endif /* __SWALOO_H_ */
