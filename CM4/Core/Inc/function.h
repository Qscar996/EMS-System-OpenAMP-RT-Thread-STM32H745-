/*
 * function.h
 *
 *  Created on: 2026年6月6日
 *      Author: 22762
 */

#ifndef INC_FUNCTION_H_
#define INC_FUNCTION_H_

#include <rthw.h>
#include <rtthread.h>
#include <rtconfig.h>
#include <usart.h>
#include "i2c.h"
#include "stdio.h"
#include "string.h"
#include "fdcan.h"
#include "rtc.h"
#include "main.h"
#include "tim.h"
#include "openamp.h"
#include "C:\Users\22762\Desktop\BMS_Pro_Main\MainBMS_RTT\Public_Lib\public.h"

extern uint8_t can_recv_fanish_flag;
extern uint8_t state_flag;
extern uint16_t time_count;
extern uint16_t time_count2;



void MX_rtt_init(void);
uint8_t get_time();
void usart_scram_write_com(uint8_t len, uint8_t dar_h, uint8_t dar_l, int value);
void usart_scram_write_com_text(uint8_t len, uint8_t dar_h, uint8_t dar_l, uint8_t *indata);
void usart_scram_read_com(uint8_t len, uint8_t dar_h, uint8_t dar_l, uint8_t rev[]);



#endif /* INC_FUNCTION_H_ */
