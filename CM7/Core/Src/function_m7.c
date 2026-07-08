/*
 * function_m7.c
 *
 *  Created on: 2026年6月9日
 *      Author: 22762
 */
#include "function_m7.h"
#include "app_x-cube-ai.h"

/********** 定义数据存储结构 *********************/

typedef enum {
    SCREEEN_GRID_ON = 22,
	SCREEEN_GRID_OFF = 21,
	SCREEEN_SOLOR_ON = 24,
	SCREEEN_SOLOR_OFF = 23,
	SCREEEN_CHG1_ON = 3,
	SCREEEN_CHG1_OFF = 4,
	SCREEEN_CHG2_ON = 3,
	SCREEEN_CHG2_OFF = 4,
	SCREEEN_DISCHG1_ON = 5,
	SCREEEN_DISCHG1_OFF = 6,
	SCREEEN_DISCHG2_ON = 5,
	SCREEEN_DISCHG2_OFF = 6,
}bms_screen_state;


/* 定义状态 */
typedef enum {
    SYS_IDLE = 0,
	SYS_POWER_GRID,
	SYS_POWER_SOLOR,
    SYS_CHARGING_1,
    SYS_CHARGING_2,
	SYS_DISCHARGING_1,
	SYS_DISCHARGING_2,
}bms_sys_state;


typedef enum {
	DAY_TIME,
	NIGHT_TIME,
    BEFOR_NIGHT_TIME,
    BACK_NIGHT_TIME,
}bms_day_state;


/******************** 核间通讯变量定义 **********************************************/
#define RPMSG_CHAN_NAME "openamp_test"
#define MAX_STR_LEN 512   // 根据实际定义修改

static volatile int message_received;//指示是否收到消息的标志位
static volatile int service_created;//
unsigned char received_data_str[MAX_STR_LEN];//接收数据变量
static struct rpmsg_endpoint rp_endpoint;
int32_t status = 0;
char data[MAX_STR_LEN]; //作为字符串的转换接收
bms_public_pack_data form_m4_all_content __attribute__((section(".sram4_section")));

/******************* 核间通讯的函数 *****************************/
int rpmsg_recv_callback(struct rpmsg_endpoint *ept, void *data, size_t len, uint32_t src, void *priv)
{
	size_t copy_len = (len < MAX_STR_LEN - 1) ? len : MAX_STR_LEN - 1;
	// 复制数据到字符数组
	memcpy(&form_m4_all_content, data, copy_len);
    message_received=1;
    return 0;
}
void service_destroy_cb(struct rpmsg_endpoint *ept)
{
    /* this function is called while remote endpoint as been destroyed, the
    * service is no more available
    */
    service_created = 0;
}

void new_service_cb(struct rpmsg_device *rdev, const char *name, uint32_t dest)
{
    /* create a endpoint for rpmsg communication */
    OPENAMP_create_endpoint(&rp_endpoint, name, dest,rpmsg_recv_callback,service_destroy_cb);
    service_created = 1;
}

unsigned int receive_message (void)//接收输出处理函数
{
    while (message_received == 0)
    {
        OPENAMP_check_for_message();
    }
    message_received = 0;
    return 0;
}


//AMP通讯初始化函数
void bms_msg_amp_init(void)
{
	MAILBOX_Init();
	/* Initialize the rpmsg endpoint to set default addresses to RPMSG_ADDR_ANY */
	rpmsg_init_ept(&rp_endpoint, RPMSG_CHAN_NAME, RPMSG_ADDR_ANY, RPMSG_ADDR_ANY, NULL, NULL);

	/* Initialize OpenAmp and libmetal libraries */
	if (MX_OPENAMP_Init(RPMSG_MASTER, new_service_cb) != HAL_OK)
	{
		Error_Handler();
	}

	/* The rpmsg service is initiate by the remote processor, on 7 new_service_cb */
	/* callback is received on service creation. Wait for the callback */
	OPENAMP_Wait_EndPointready(&rp_endpoint);



}
 /******* *****/
uint8_t event_flag = 0;
char data[512];
char test_printf[128];

/********************************************************************************/

bms_day_state day_time_state __attribute__((section(".sram4_section")));
bms_screen_touch_data return_screen_data __attribute__((section(".sram4_section")));
bms_screen_state current_screen_state __attribute__((section(".sram4_section")));


void solution_bms_data(void)
{
	/* 测试打印 */
	//sprintf(test_printf,"%0.1f %0.1f %0.1f %0.1f",form_m4_all_content.gridi,form_m4_all_content.gridv,form_m4_all_content.solori,form_m4_all_content.solorv);
//	sprintf(test_printf,"%d %d %d %d %d %d %d %d",battery1data.bms_battery_i,battery1data.bms_battery_v
//			,battery1data.bms_battery_t,battery1data.bms_battery_v1,battery1data.bms_battery_v2,
//			battery1data.bms_battery_v3,battery1data.bms_battery_v4,battery1data.bms_battery_v5);
	sprintf(test_printf,"%d %d %d %d %d %d %d %d %d %d %d %d %d",form_m4_all_content.Mode,form_m4_all_content.charge1,
			form_m4_all_content.charge2,form_m4_all_content.discharge1,form_m4_all_content.discharge2,form_m4_all_content.grid_ctl,
			form_m4_all_content.solor_ctl,form_m4_all_content.fan1_ctl,form_m4_all_content.fan2_ctl,form_m4_all_content.bms_date,form_m4_all_content.bms_set_temp
			,form_m4_all_content.bms_battery_t,form_m4_all_content.bms_battery2_t);
	HAL_UART_Transmit (&huart5, (uint8_t *)test_printf, strlen((char *)test_printf), 100);
}

/*手动控制策略*/
char send_data1[128]={0};
char strg[10]="00",strs[10]="00",strc1[10]="00",strc2[10]="00",strdc1[10]="00",strdc2[10]="00";
char *strfirst = "A";
uint8_t cha1mand1 = 0x1D,cha1mand2 = 0x2D,cha1mand3 = 0x3D;
uint8_t cha2mand1 = 0x1E,cha2mand2 = 0x2E,cha2mand3 = 0x3E;
uint8_t end1mand = 0x1F;
uint8_t end2mand = 0x2F;
void ctl_conmand_manual(void)
{
	/* 业务逻辑
	 * ①首先就是命令有变化后在更新控制，默认不需要执行任何操作
	 * ②其次风扇控制（输出PWM实现风扇控制）
	 * ③充电1、充电2只能执行其一（任一个开始充电就不能进行放电）
	 * ④放电1、放电2只能执行其一
	 * ⑤电源的输入控制（光伏还是电网）*/
	static uint8_t last_mand[9] = {4,4,21,23,1,1,6,6,0};
	static bms_sys_state last_power_state = SYS_IDLE;
	static bms_sys_state target_power_state = SYS_IDLE;
	static bms_sys_state last_chg_state = SYS_IDLE;
	static bms_sys_state target_chg_state = SYS_IDLE;
	static bms_sys_state last_dischg_state = SYS_IDLE;
	static bms_sys_state target_dischg_state = SYS_IDLE;


	/* 输入电源判断 */

	//电网的判断
	if(form_m4_all_content.grid_ctl == SCREEEN_GRID_ON)
	{
		target_power_state = SYS_POWER_GRID;
	}
	else if(form_m4_all_content.solor_ctl == SCREEEN_SOLOR_ON)
	{
		target_power_state = SYS_POWER_SOLOR;
	}
	else
	{
		target_power_state = SYS_IDLE;
	}
	if(last_power_state != target_power_state)
	{
		//HAL_UART_Transmit (&huart5, (uint8_t *)"in power\r\n", 10, 100);
		switch(target_power_state)
		{
			case SYS_POWER_GRID:
				return_screen_data.grid_state = 1;
				return_screen_data.solor_state = 0;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
				break;
			case SYS_POWER_SOLOR:
				return_screen_data.grid_state = 0;
				return_screen_data.solor_state = 1;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
				break;
			case SYS_IDLE:
			default:
				return_screen_data.grid_state = 0;
				return_screen_data.solor_state = 0;
				break;
		}
		last_power_state = target_power_state;
	}

	if(target_power_state != SYS_IDLE)
	{

		if(form_m4_all_content.charge1 == SCREEEN_CHG1_ON)
		{
			target_chg_state = SYS_CHARGING_1;
		}
		else if(form_m4_all_content.charge2 == SCREEEN_CHG2_ON)
		{
			target_chg_state = SYS_CHARGING_2;
		}
		else
		{
			target_chg_state = SYS_IDLE;
		}
		if(last_chg_state != target_chg_state)
		{
			//HAL_UART_Transmit (&huart5, (uint8_t *)"in chg\r\n", 8, 100);
			switch(target_chg_state)
			{
				case SYS_CHARGING_1:
					//放电1关闭，放电2开启
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
					return_screen_data.dischg1_state = 0;
					return_screen_data.dischg2_state = 1;
					HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
					HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
					break;
				case SYS_CHARGING_2:
					//放电2关闭，放电1开启
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
					return_screen_data.dischg1_state = 1;
					return_screen_data.dischg2_state = 0;
					HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
					HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
					break;
				case SYS_IDLE:
				default:
					HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
					HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
					return_screen_data.dischg1_state = 0;
					return_screen_data.dischg2_state = 0;
					break;
			}
			last_chg_state = target_chg_state;
		}

	}
	if(target_chg_state == SYS_IDLE)
	{

		if(form_m4_all_content.discharge1 == SCREEEN_DISCHG1_ON)
		{
			target_dischg_state = SYS_DISCHARGING_1;
		}
		else if(form_m4_all_content.discharge2 == SCREEEN_DISCHG2_ON)
		{
			target_dischg_state = SYS_DISCHARGING_2;
		}
		else
		{
			target_dischg_state = SYS_IDLE;
		}
		if(last_dischg_state != target_dischg_state)
		{
			//HAL_UART_Transmit (&huart5, (uint8_t *)"in dischg\r\n", 11, 100);
			switch(target_dischg_state)
			{
				case SYS_DISCHARGING_1:
					//放电1开启
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
					return_screen_data.dischg1_state = 1;
					return_screen_data.dischg2_state = 0;
					break;
				case SYS_DISCHARGING_2:
					//放电2开启
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
					return_screen_data.dischg2_state = 1;
					return_screen_data.dischg1_state = 0;
					break;
				case SYS_IDLE:
				default:
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
					return_screen_data.dischg1_state = 0;
					return_screen_data.dischg2_state = 0;
					break;
			}
			last_dischg_state = target_dischg_state;
		}

	}
	/* 风扇的控制 */
	if(last_mand[4] != form_m4_all_content.fan1_ctl)
	{
		switch(form_m4_all_content.fan1_ctl)
		{
			case 1:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
				break;
			case 2:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
				break;
			case 3:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 550);
				break;
			case 4:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 600);
				break;
			case 5:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 650);
				break;
			case 6:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 700);
				break;
			case 7:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 750);
				break;
			case 8:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 800);
				break;
			case 9:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 850);
				break;
			case 10:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 900);
				break;
			case 11:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 950);
				break;
			default :
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
				break;
		}
		last_mand[4] = form_m4_all_content.fan1_ctl;
	}
	if(last_mand[5] != form_m4_all_content.fan2_ctl)
	{
		switch(form_m4_all_content.fan2_ctl)
		{
			case 1:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
				break;
			case 2:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 500);
				break;
			case 3:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 550);
				break;
			case 4:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 600);
				break;
			case 5:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 650);
				break;
			case 6:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 700);
				break;
			case 7:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 750);
				break;
			case 8:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 800);
				break;
			case 9:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 850);
				break;
			case 10:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 900);
				break;
			case 11:
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 950);
				break;
			default :
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
				break;
		}
		last_mand[5] = form_m4_all_content.fan2_ctl;
	}
}

/*自动控制*/
char send_data[10]={0};
void ctl_conmand_auto(void)
{
	/*自动控制逻辑*/
	/*
	 * 结合：当前电价（手机设置） + 未来负荷预测 + 电池 SoC（电量）
	 * 逻辑：
	 * 1.极端低电量保护（优先级最高）：SoCA < 10%，SoCB < 10% ======两块同时进行充电；
	 *
	 * 2.部分保护：SoC_A < 10% 或 SoC_B < 10% ===== 给低于 10% 的那块电池充电
	 *
	 * 3.谷电价时段（省钱充电）：Price_Now == 1 (谷价/低价) 且 （SoCA < 95% 或 SoCB<95%）
	 * 		双电池进行充电；
	 *
	 * 4.峰电价 + 预测未来有高负荷（削峰填谷）：
	 * 		Price_Now == 3 (峰价/高价) 且 Load_Forecast > Load_Threshold 且 SoCA > 30%且SoCB > 30%
	 * 		双电池同时进行供电；
	 *
	 * 5.峰电价 + 预测未来负荷平稳（经济套利）：
	 * 		Price_Now == 3 (峰价/高价) 且 Load_Forecast < Load_Threshold 且 ,SoC > 35%
	 * 		如果SoCA > SoCB：电池A放电；
	 * 		如果SoCA < SoCB：电池B放电；
	 *
	 * 6.平时状态（平价状态） + 有光伏（光伏利用）
	 * 		光伏电压 > 0 ,SOCA < 95% 或 SOCB < 95% 光伏充电。
	 * 		如果SoCA < SoCB：电池A充电；
	 * 		如果SoCA > SoCB：电池B充电；
	 *
	 * 6.上述条件不满足，系统待机
	 * */
	// 1. 极端双低保护
	if(form_m4_all_content.soc_1 < 10 && form_m4_all_content.soc_2 < 10)
	{
		if(form_m4_all_content.solorv > 0)
		{
			return_screen_data.grid_state = 0;
			return_screen_data.solor_state = 1;
		}
		else
		{
			return_screen_data.grid_state = 1;
			return_screen_data.solor_state = 0;
		}
	    // 停止放电
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	    // 强制双充
	    HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
	    HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
	    return_screen_data.chg1_state = 1; return_screen_data.chg2_state = 1;
	    return_screen_data.dischg1_state = 0; return_screen_data.dischg2_state = 0;
	}
	// 2. 单电池保护
	else if(form_m4_all_content.soc_1 < 10 || form_m4_all_content.soc_2 < 10)
	{
		if(form_m4_all_content.solorv > 0)
		{
			return_screen_data.grid_state = 0;
			return_screen_data.solor_state = 1;
		}
		else
		{
			return_screen_data.grid_state = 1;
			return_screen_data.solor_state = 0;
		}
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // 停止放电
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	    return_screen_data.dischg1_state = 0;
	    return_screen_data.dischg2_state = 0;
	    if(form_m4_all_content.soc_1 < 10)
	    {
	        HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
	        return_screen_data.chg1_state = 1;
	        return_screen_data.chg2_state = 0;
	    }
	    else
	    {
	        HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
	        return_screen_data.chg1_state = 0;
	        return_screen_data.chg2_state = 1;
	    }
	}
	// 3. 谷电价充电
	else if(form_m4_all_content.firm_price < 0.5 && (form_m4_all_content.soc_1 < 95 || form_m4_all_content.soc_2 < 95))
	{
		return_screen_data.grid_state = 1;
		return_screen_data.solor_state = 0;
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // 停止放电
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	    return_screen_data.dischg1_state = 0;
	    return_screen_data.dischg2_state = 0;
	    // 谁没满冲谁
	    if(form_m4_all_content.soc_1 < 95)
	    	HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
	    else if(form_m4_all_content.soc_2 < 95)
	    	HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);

	}
//	// 4. 峰电价 + 高负荷 -> 双放 (增加 SoC > 15 保护)
//	else if(form_m4_all_content.firm_price > 0.5 && form_m4_all_content.bms_battery_power > 6.4 && form_m4_all_content.soc_1 > 15 && form_m4_all_content.soc_2 > 15)
//	{
//	    HAL_UART_Transmit(&huart6, &end1mand, 1, 100); // 停止充电
//	    HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); // 双放
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
//	    return_screen_data.dischg1_state = 1; return_screen_data.dischg2_state = 1;
//	}
//	// 5. 峰电价 + 低负荷 -> 择优单放 (增加 SoC > 20 保护)
//	else if(form_m4_all_content.firm_price > 0.5 && (form_m4_all_content.soc_1 > 20 || form_m4_all_content.soc_2 > 20))
//	{
//	    HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//	    HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//	    if(form_m4_all_content.soc_1 > form_m4_all_content.soc_2) {
//	        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); // A放
//	        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);   // B停
//	    } else {
//	        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
//	        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // B放
//	    }
//	}
//	// 6. 光伏充电逻辑 (平价电或平时)
//	else if(form_m4_all_content.solorv > 0 && (form_m4_all_content.soc_1 < 95 || form_m4_all_content.soc_2 < 95))
//	{
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // 停止放电
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
//	    // 择优充电：谁电少冲谁
//	    if(form_m4_all_content.soc_1 < form_m4_all_content.soc_2) {
//	        HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
//	        HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//	    } else {
//	        HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//	        HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
//	    }
//	}
	// 7. 兜底待机
//	else
//	{
//	    HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//	    HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
//	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
//	}


//	if(form_m4_all_content.soc_1 < 10 && form_m4_all_content.soc_2 < 10)
//	{
//		HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
//		HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
//		return_screen_data.chg1_state = 1;
//		return_screen_data.chg2_state = 1;
//	}
//	else if(form_m4_all_content.soc_1 < 10 || form_m4_all_content.soc_2 < 10)
//	{
//		if(form_m4_all_content.soc_1 < 10)
//		{
//			HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
//			HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//			return_screen_data.chg1_state = 1;
//			return_screen_data.chg2_state = 0;
//		}
//		else
//		{
//			HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
//			HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//			return_screen_data.chg1_state = 0;
//			return_screen_data.chg2_state = 1;
//		}
//	}
//	//正常的电价：0.5
//	else if(form_m4_all_content.firm_price < 0.5 && form_m4_all_content.soc_1 < 95 && form_m4_all_content.soc_2 < 95)
//	{
//		HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
//		HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
//		return_screen_data.chg1_state = 1;
//		return_screen_data.chg2_state = 1;
//	}
//	//正常的负荷：16000*400 = 6.4w
//	else if(form_m4_all_content.firm_price > 0.5 && form_m4_all_content.bms_battery_power > 6.4)
//	{
//		HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//		HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//		return_screen_data.chg1_state = 0;
//		return_screen_data.chg2_state = 0;
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
//		return_screen_data.dischg1_state = 1;
//		return_screen_data.dischg2_state = 1;
//	}
//	else if(form_m4_all_content.firm_price > 0.5 && form_m4_all_content.bms_battery_power < 6.4)
//	{
//		if(form_m4_all_content.soc_1 > form_m4_all_content.soc_2)
//		{
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
//			return_screen_data.dischg1_state = 1;
//			return_screen_data.dischg2_state = 0;
//		}
//		else
//		{
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
//			return_screen_data.dischg1_state = 0;
//			return_screen_data.dischg2_state = 1;
//		}
//	}
//
//	else if(form_m4_all_content.firm_price == 0.5 && form_m4_all_content.solorv > 0)
//	{
//		if(form_m4_all_content.soc_1 < 95 || form_m4_all_content.soc_2 < 95)
//		{
//			if(form_m4_all_content.soc_1 > form_m4_all_content.soc_2)
//			{
//				HAL_UART_Transmit(&huart6, &end1mand, 1, 100);
//				HAL_UART_Transmit(&huart6, &cha2mand3, 1, 100);
//				return_screen_data.chg1_state = 0;
//				return_screen_data.chg2_state = 1;
//			}
//			else
//			{
//				HAL_UART_Transmit(&huart6, &end2mand, 1, 100);
//				HAL_UART_Transmit(&huart6, &cha1mand3, 1, 100);
//				return_screen_data.chg1_state = 1;
//				return_screen_data.chg2_state = 0;
//			}
//		}
//	}


/***************************************************************************************/
	static bms_sys_state bettery1_state = SYS_IDLE;
	static bms_sys_state bettery2_state = SYS_IDLE;
	/* 自动调温 */
	switch((int)(form_m4_all_content.bms_battery_t/10 - form_m4_all_content.bms_set_temp/10))
	{
		case 0:
			//usart_scram_write_com(0x02, 0x15, 0x00, 2);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			return_screen_data.fan1_state = 1;
			break;
		case 1:
			//usart_scram_write_com(0x02, 0x15, 0x00, 2);
			//HAL_UART_Transmit (&huart5, (uint8_t *)"is B1\r\n", 7, 100);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
			return_screen_data.fan1_state = 2;
			break;
		case 2:
			//HAL_UART_Transmit (&huart5, (uint8_t *)"is B2\r\n", 7, 100);
			//usart_scram_write_com(0x02, 0x15, 0x00, 3);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 550);
			return_screen_data.fan1_state = 3;
			break;
		case 3:
			//usart_scram_write_com(0x02, 0x15, 0x00, 4);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 600);
			return_screen_data.fan1_state = 4;
			break;
		case 4:
			//usart_scram_write_com(0x02, 0x15, 0x00, 5);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 650);
			return_screen_data.fan1_state = 5;
			break;
		case 5:
			//usart_scram_write_com(0x02, 0x15, 0x00, 6);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 700);
			return_screen_data.fan1_state = 6;
			break;
		case 6:
			//usart_scram_write_com(0x02, 0x15, 0x00, 7);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 750);
			return_screen_data.fan1_state = 7;
			break;
		default :
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			return_screen_data.fan1_state = 0;
			break;
	}
	switch((int)(form_m4_all_content.bms_battery2_t/10 - form_m4_all_content.bms_set_temp/10))
	{
		case 0:
			//usart_scram_write_com(0x02, 0x15, 0x00, 2);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
			return_screen_data.fan2_state = 1;
			break;
		case 1:
			//usart_scram_write_com(0x02, 0x15, 0x00, 2);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 500);
			return_screen_data.fan2_state = 2;
			break;
		case 2:
			//usart_scram_write_com(0x02, 0x15, 0x00, 3);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 550);
			return_screen_data.fan2_state = 3;
			break;
		case 3:
			//usart_scram_write_com(0x02, 0x15, 0x00, 4);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 600);
			return_screen_data.fan2_state = 4;
			break;
		case 4:
			//usart_scram_write_com(0x02, 0x15, 0x00, 5);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 650);
			return_screen_data.fan2_state = 5;
			break;
		case 5:
			//usart_scram_write_com(0x02, 0x15, 0x00, 6);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 700);
			return_screen_data.fan2_state = 6;
			break;
		case 6:
			//usart_scram_write_com(0x02, 0x15, 0x00, 7);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 750);
			return_screen_data.fan2_state = 7;
			break;
		default :
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
			return_screen_data.fan2_state = 0;
			break;
	}
}

uint16_t last_minutes = 0;
uint16_t count_data = 0;
//数据指令发送和接收
void recv_to_bms_m4(void)
{
	//发送指令（屏幕控件的状态指令）
	char model_msg[32];
	static uint16_t count = 0;
	float model_input[9];
	return_screen_data.requst = 'A';
	status = OPENAMP_send(&rp_endpoint, &return_screen_data, sizeof(return_screen_data));
	if (status < 0)
	{
		Error_Handler();
	}
	//接收数据【一定要将上面的初始化注释掉】
	receive_message ();
	switch(event_flag)
	{
		case 0:
			//solution_bms_data();
			event_flag = 1;
			break;
		case 1:
			//solution_bms_data();
			if(form_m4_all_content.Mode == 7)
				ctl_conmand_manual();
			else
				ctl_conmand_auto();
			break;
	}
	HAL_Delay(500);
	/*AI模型推理：*/
	/* 将当前的功率进行填充，当满足120分钟后开始进行推理*/
	if(form_m4_all_content.bms_minutes != last_minutes)
	{
		count_data ++;
		update_power_buffer(form_m4_all_content.bms_battery_power);
		sprintf(model_msg, "Collecting power data: %d / 120\r\n",count_data);
		HAL_UART_Transmit (&huart5, (uint8_t *)model_msg, strlen(model_msg), 100);
		last_minutes = form_m4_all_content.bms_minutes;
		if(count_data >= 15)
		{
			//已满
			if(count_data >= 120)
				count_data = 0;
			MX_X_CUBE_AI_Process();
			return_screen_data.bms_future_load = pred_w;

		}
	}

	//将数据上传到串口上
}
