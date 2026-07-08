/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "string.h"
#include <rtthread.h>

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define RX_SIZE 500
#define RX_SIZE_MQTT 128
extern DMA_HandleTypeDef hdma_usart3_rx;
extern uint8_t buffer_index;
extern uint8_t buffer[];
extern uint8_t recv_flag;
extern uint8_t rx_data;// 用于单字节接收的临时变量
extern uint8_t rx_data2;
extern uint8_t recv_flag2;
extern uint8_t mqtt_buffer[RX_SIZE];
extern char buf[];
extern uint8_t rx_dmabuffer[RX_SIZE_MQTT];           // DMA接收缓冲区
extern uint8_t dma_process_buffer[RX_SIZE_MQTT]; // 处理缓冲区
extern uint8_t newdam_msg_flag;
extern uint16_t rx_dmadata_len;


/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
int AT_WaitResp(char *expected, uint32_t timeout_ms);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

