/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
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
/* Includes ------------------------------------------------------------------*/
#include "fdcan.h"

/* USER CODE BEGIN 0 */
#include "function.h"
/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 5;
  hfdcan1.Init.NominalSyncJumpWidth = 2;
  hfdcan1.Init.NominalTimeSeg1 = 15;
  hfdcan1.Init.NominalTimeSeg2 = 4;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 1;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 1;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.RxFifo0ElmtsNbr = 16;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 16;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */

  /* USER CODE END FDCAN1_Init 2 */

}

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
    PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* FDCAN1 clock enable */
    __HAL_RCC_FDCAN_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PB8     ------> FDCAN1_RX
    PB9     ------> FDCAN1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PB8     ------> FDCAN1_RX
    PB9     ------> FDCAN1_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8|GPIO_PIN_9);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/*代码添加*/
/* 定义 CAN 通信参数（根据从机协议修改） */
#define HOST_REQUEST_ID1   0x0001   // 主机发送请求时使用的ID
#define HOST_REQUEST_ID2   0x0002   // 主机发送请求时使用的ID
#define SLAVE_CAN_ID       0x321   /* 从机 CAN ID */
#define REQUEST_DLC        1       /* 请求帧数据长度(发送字节长度) */
#define RX_TIMEOUT_MS      500     /* 接收超时时间（毫秒） */
extern UART_HandleTypeDef huart2;

/* 全局变量：接收标志 */
uint8_t rx_done_flag = 0;
uint8_t rx_data_can[64];
FDCAN_RxHeaderTypeDef rx_header;
uint8_t state_flag = 0;

/**
  * @brief 配置 FDCAN 过滤器（接收标准 ID SLAVE_CAN_ID）
  */
void Config_FDCAN_Filter(void) {
    FDCAN_FilterTypeDef filter;
    filter.IdType = FDCAN_STANDARD_ID;
    filter.FilterIndex = 0;                 /* 使用过滤器 0 */
    filter.FilterType = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    filter.FilterID1 = 0x00;        /* 对所有的ID都接收 */
    filter.FilterID2 = 0x00;       /* 掩码全0，所有ID都接收 */
    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &filter) != HAL_OK) {
        Error_Handler();
    }
}

/* FDCAN 接收完成回调（在中断中调用） */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef* hfdcan, uint32_t RxFifo0ITs) {
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
        /* 读取接收到的消息 */
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_data_can) == HAL_OK) {
            rx_done_flag = 1;
        }
    }
}

/* 将接收到的 CAN 数据通过 USART2 打印（十六进制格式） */
void Print_Can_Data(uint8_t* data, uint32_t dlc)
{
//    char msg[64];
//    int len = 0;
//    len += snprintf(msg + len, sizeof(msg) - len, "CAN RX: ");
//    for (uint32_t i = 0; i < dlc && i < 8; i++) {
//        len += snprintf(msg + len, sizeof(msg) - len, "%02X ", data[i]);
//    }
//    len += snprintf(msg + len, sizeof(msg) - len, "\r\n");
    //HAL_UART_Transmit(&huart2, (uint8_t*)data, dlc, 100);
}

/*将CAN收到的数据保存并通过ESP8266发送出去*/
int16_t databuf[10] = {0};
int16_t databuf2[10] = {0};
uint8_t can_recv_fanish_flag = 0;

void CAN_data_store(uint8_t* data, uint32_t dlc, uint8_t sw)
{
	switch(state_flag)
	{
		case 1:
			can_recv_fanish_flag = 0;
			databuf[sw] = ((int16_t)data[0]<<8) | data[1];
			break;
		case 2:
			can_recv_fanish_flag = 0;
			databuf2[sw] = ((int16_t)data[0]<<8) | data[1];
			break;
	}
	if(sw == 9)
	{
		can_recv_fanish_flag = 1;
	}

}


void Read_From_Slave1(uint8_t sw)
{
    FDCAN_TxHeaderTypeDef tx_header;
    uint8_t tx_data[1] = {0};
    state_flag = 1;
    /* 1. 发送请求帧（标准数据帧，DLC=0，表示读取请求）配置发送帧头 (Classic CAN 2.0模式) */
    switch(sw)
    {
    	case 0:tx_data[0]=0x01;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 1:tx_data[0]=0x02;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 2:tx_data[0]=0x03;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 3:tx_data[0]=0x04;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 4:tx_data[0]=0x05;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 5:tx_data[0]=0x06;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 6:tx_data[0]=0x07;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 7:tx_data[0]=0x08;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 8:tx_data[0]=0x09;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	case 9:tx_data[0]=0x0A;tx_header.Identifier = HOST_REQUEST_ID1;break;
    	//case 4:tx_data[0]=0x02;tx_header.Identifier = HOST_REQUEST_ID2;break;
    }
    tx_header.IdType = FDCAN_STANDARD_ID;
    tx_header.TxFrameType = FDCAN_DATA_FRAME;   /* 数据帧（也可用远程帧，按需选择） */
    tx_header.DataLength = REQUEST_DLC;
    tx_header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    tx_header.BitRateSwitch = FDCAN_BRS_OFF;
    tx_header.FDFormat = FDCAN_CLASSIC_CAN;
    tx_header.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    tx_header.MessageMarker = 0;

    // 将消息加入发送FIFO队列
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_header, tx_data) != HAL_OK)
    {
        //char err_msg[] = "CAN Tx error\r\n";
       //HAL_UART_Transmit(&huart2, (uint8_t*)err_msg, strlen(err_msg), 100);
        return;
    }

    /* 2. 等待接收响应（超时机制） */
    rx_done_flag = 0;
    uint32_t start_tick = HAL_GetTick();
    while ((HAL_GetTick() - start_tick) < RX_TIMEOUT_MS)
    {
        if (rx_done_flag)
        {
        	//Print_Can_Data(rx_data_can, rx_header.DataLength);
            /* 收到数据，将数据保存起来 */
        	CAN_data_store(rx_data_can, rx_header.DataLength,sw);
            return;
        }
        //HAL_Delay(1);
    }

    /* 超时未收到 */
    //char timeout_msg[] = "CAN RX timeout\r\n";
    //HAL_UART_Transmit(&huart2, (uint8_t*)timeout_msg, strlen(timeout_msg), 100);
}

void Read_From_Slave2(uint8_t sw)
{
    FDCAN_TxHeaderTypeDef tx_header;
    uint8_t tx_data[1] = {0};
    state_flag = 2;
    /* 1. 发送请求帧（标准数据帧，DLC=0，表示读取请求）配置发送帧头 (Classic CAN 2.0模式) */
    switch(sw)
    {
    	case 0:tx_data[0]=0x01;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 1:tx_data[0]=0x02;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 2:tx_data[0]=0x03;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 3:tx_data[0]=0x04;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 4:tx_data[0]=0x05;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 5:tx_data[0]=0x06;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 6:tx_data[0]=0x07;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 7:tx_data[0]=0x08;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 8:tx_data[0]=0x09;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	case 9:tx_data[0]=0x0A;tx_header.Identifier = HOST_REQUEST_ID2;break;
    	//case 4:tx_data[0]=0x02;tx_header.Identifier = HOST_REQUEST_ID2;break;
    }
    tx_header.IdType = FDCAN_STANDARD_ID;
    tx_header.TxFrameType = FDCAN_DATA_FRAME;   /* 数据帧（也可用远程帧，按需选择） */
    tx_header.DataLength = REQUEST_DLC;
    tx_header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    tx_header.BitRateSwitch = FDCAN_BRS_OFF;
    tx_header.FDFormat = FDCAN_CLASSIC_CAN;
    tx_header.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    tx_header.MessageMarker = 0;

    // 将消息加入发送FIFO队列
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_header, tx_data) != HAL_OK)
    {
        //char err_msg[] = "CAN Tx error\r\n";
        //HAL_UART_Transmit(&huart2, (uint8_t*)err_msg, strlen(err_msg), 100);
        return;
    }

    /* 2. 等待接收响应（超时机制） */
    rx_done_flag = 0;
    uint32_t start_tick = HAL_GetTick();
    while ((HAL_GetTick() - start_tick) < RX_TIMEOUT_MS)
    {
        if (rx_done_flag)
        {
        	//Print_Can_Data(rx_data_can, rx_header.DataLength);
            /* 收到数据，将数据保存起来 */
        	CAN_data_store(rx_data_can, rx_header.DataLength, sw);
            return;
        }
       // HAL_Delay(1);
    }

    /* 超时未收到 */
    //char timeout_msg[] = "CAN RX timeout\r\n";
    //HAL_UART_Transmit(&huart2, (uint8_t*)timeout_msg, strlen(timeout_msg), 100);
}

/* USER CODE END 1 */

