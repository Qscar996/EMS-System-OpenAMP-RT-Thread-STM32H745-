
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
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

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\[user_name]\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "bms_model.h"
#include "bms_model_data.h"

/* USER CODE BEGIN includes */
#include "bms_ai_model.h"
#include "usart.h"



#define POWER_LOOKBACK 120

float power_buffer[POWER_LOOKBACK];
uint16_t power_index = 0;
uint16_t power_count = 0;

float pred_w;

/* 更新120分钟功率缓存 */
void update_power_buffer(float power_w)
{
    if (power_w < 0.0f)
    {
        power_w = 0.0f;
    }

    if (power_w > 6.0f)
    {
        power_w = 6.0f;
    }

    power_buffer[power_index] = power_w;

    power_index++;
    if (power_index >= POWER_LOOKBACK)
    {
        power_index = 0;
    }

    if (power_count < POWER_LOOKBACK)
    {
        power_count++;
    }
}


/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_BMS_MODEL_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_BMS_MODEL_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_BMS_MODEL_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_BMS_MODEL_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_BMS_MODEL_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_BMS_MODEL_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_BMS_MODEL_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_BMS_MODEL_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_BMS_MODEL_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle bms_model = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_bms_model_create_and_init(&bms_model, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_bms_model_create_and_init");
    return -1;
  }

  ai_input = ai_bms_model_inputs_get(bms_model, NULL);
  ai_output = ai_bms_model_outputs_get(bms_model, NULL);

#if defined(AI_BMS_MODEL_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_BMS_MODEL_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_BMS_MODEL_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_BMS_MODEL_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_BMS_MODEL_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_BMS_MODEL_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_bms_model_run(bms_model, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_bms_model_get_error(bms_model),
        "ai_bms_model_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[])
{
  /* fill the inputs of the c-model
  for (int idx=0; idx < AI_BMS_MODEL_IN_NUM; idx++ )
  {
      data[idx] = ....
  }

  */
	char model_msg[64];
	ai_float *input_data = (ai_float *)data[0];
	/*
	   power_index 指向下一次写入位置。
	   缓存满后，它也正好指向最旧的数据。
	   从 power_index 开始取，就是从旧到新。
	*/
	uint16_t start_index = power_index;
	for (uint16_t i = 0; i < POWER_LOOKBACK; i++)
	{
		uint16_t idx = (start_index + i) % POWER_LOOKBACK;

		float power_w = power_buffer[idx];

		input_data[i] = poweronly_noaux_standardize_power(power_w);
	}

	sprintf(model_msg, "AI input prepared from simulated power buffer.\r\n");
	HAL_UART_Transmit (&huart5, (uint8_t *)model_msg, strlen(model_msg), 100);
	return 0;
}

int post_process(ai_i8* data[])
{
  /* process the predictions
  for (int idx=0; idx < AI_BMS_MODEL_OUT_NUM; idx++ )
  {
      data[idx] = ....
  }

  */
	char model_msg[32];
	ai_float *output_data = (ai_float *)data[0];              //取出缓存结果
	float pred_scaled = output_data[0];
	pred_w = poweronly_noaux_inverse_output(pred_scaled);  //进行反标准化
	sprintf(model_msg, "AI out power is:%.2f.\r\n",pred_w);
	HAL_UART_Transmit (&huart5, (uint8_t *)model_msg, strlen(model_msg), 100);
	return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
	int res = -1;
	char model_msg[64];


	if (bms_model)
	{
		/* 1. 从 power_buffer 构造模型输入 */
		res = acquire_and_process_data(data_ins);

		/* 2. 运行 AI 模型 */
		if (res == 0)
		{
			res = ai_run();
		}

		/* 3. 反标准化并打印结果 */
		if (res == 0)
		{
			res = post_process(data_outs);
		}
	}

	if (res)
	{
		ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
		ai_log_err(err, "Process has FAILED");
	}
	else
	{
		sprintf(model_msg, "AI simulated power test finished\r\n");
		HAL_UART_Transmit (&huart5, (uint8_t *)model_msg, strlen(model_msg), 100);
	}
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
