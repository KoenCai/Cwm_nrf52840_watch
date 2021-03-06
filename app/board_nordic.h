#ifndef __BOARD_NORDIC_H
#define __BOARD_NORDIC_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "boards.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_drv_clock.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "app_timer.h"
#include "app_uart.h"
#include "nrf_uart.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_twi.h"
#include "nrf_drv_rtc.h"
#include "nrf_drv_clock.h"
#include "cwm_lib_api.h"

/*************** GPIO/E define ***************/
#define INT_pin                 25
#define pin_out                 13

/*************** JLINK PRINTF ***************/
#define USE_JLINK_PRINTF        0

/*************** UART CONFIG ***************/
#define UART_TX_BUF_SIZE        2048
#define UART_RX_BUF_SIZE        2048
#define UART_HWFC               APP_UART_FLOW_CONTROL_DISABLED
#define UART_BAUD_SIZE	        NRF_UART_BAUDRATE_921600

/*************** TWI CONFIG ***************/
#define TWI_INSTANCE_ID         1

/*************** TIMER CONFIG ***************/
#define TIMER_PERIOD_1_SEC      APP_TIMER_TICKS(1000)
#define TIMER_PERIOD_60_SEC     APP_TIMER_TICKS(60000)

#define ONE_TIME_TIME           APP_TIMER_TICKS(1000)
/*************** RTC CONFIG ***************/
#define RTC_CHANNEL             NRF_DRV_RTC_INSTANCE(0)


void board_init(void);
int CWM_OS_i2cRead(uint8_t slaveAddr, uint8_t reg, uint8_t regLength, uint8_t *readData, uint8_t readDataSize, int argument);
int CWM_OS_i2cWrite(uint8_t slaveAddr, uint8_t reg, uint8_t regLength, uint8_t *writeData, uint8_t writeDataSize, int argument);

void CWM_OS_uSleep(uint32_t time);
uint64_t CWM_OS_GetTimeNs(void);
void *CWM_OS_malloc(int size);
void CWM_OS_free(void *ptr);
int CWM_OS_dbgOutput(const char *format);
int CWM_OS_dbgOutput_checkLog(const char *format);
int CWM_OS_dbgPrintf(const char *format, ...);
void button_process(void);
uint64_t getDTus(void);

#endif
