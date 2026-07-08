/*
 * bms_ai_model.h
 *
 *  Created on: 2026年6月12日
 *      Author: 22762
 */

#ifndef INC_BMS_AI_MODEL_H_
#define INC_BMS_AI_MODEL_H_


#include <stdint.h>

#define POWERONLY_NOAUX_LOOKBACK 120
#define POWERONLY_NOAUX_SEQ_FEATURES 1
#define POWERONLY_NOAUX_OUTPUT_SIZE 1
#define POWERONLY_NOAUX_POWER_MIN_W 0.0f
#define POWERONLY_NOAUX_POWER_MAX_W 6.0f

static const float g_poweronly_noaux_seq_mean[1] = {
    1.2220451832f
};

static const float g_poweronly_noaux_seq_scale[1] = {
    1.3263812065f
};

static const float g_poweronly_noaux_y_mean = 1.2219815254f;
static const float g_poweronly_noaux_y_scale = 1.2480300665f;

static inline float poweronly_noaux_standardize_power(float power_w)
{
    return (power_w - g_poweronly_noaux_seq_mean[0]) / g_poweronly_noaux_seq_scale[0];
}

static inline float poweronly_noaux_inverse_output(float y_scaled)
{
    float y_w = y_scaled * g_poweronly_noaux_y_scale + g_poweronly_noaux_y_mean;
    if (y_w < POWERONLY_NOAUX_POWER_MIN_W) y_w = POWERONLY_NOAUX_POWER_MIN_W;
    if (y_w > POWERONLY_NOAUX_POWER_MAX_W) y_w = POWERONLY_NOAUX_POWER_MAX_W;
    return y_w;
}


#define POWER_LOOKBACK 120
/* 外部定义*/
extern float power_buffer[POWER_LOOKBACK];
extern uint16_t power_index;
extern uint16_t power_count;
extern float pred_w;

/* 更新120分钟功率缓存 */
void update_power_buffer(float power_w);

#endif /* INC_BMS_AI_MODEL_H_ */
