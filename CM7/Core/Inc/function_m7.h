/*
 * function_m7.h
 *
 *  Created on: 2026年6月9日
 *      Author: 22762
 */

#ifndef INC_FUNCTION_M7_H_
#define INC_FUNCTION_M7_H_

#include "openamp.h"
#include "usart.h"
#include "stdio.h"
#include "gpio.h"
#include "tim.h"
#include "C:\Users\22762\Desktop\BMS_Pro_Main\MainBMS_RTT\Public_Lib\public.h"
#include "bms_ai_model.h"


extern int sample_num;
extern float current_power_array[] ;


int rpmsg_recv_callback(struct rpmsg_endpoint *ept, void *data, size_t len, uint32_t src, void *priv);
unsigned int receive_message(void);
void service_destroy_cb(struct rpmsg_endpoint *ept);//摧毁服务的函数
void new_service_cb(struct rpmsg_device *rdev, const char *name, uint32_t dest);//创建服务的函数
void bms_msg_amp_init(void);
void recv_to_bms_m4(void);


#endif /* INC_FUNCTION_M7_H_ */
