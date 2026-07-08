/*
 * Function.c
 *
 *  Created on: 2026年6月6日
 *      Author: 22762
 */
#include "function.h"

/*下面线程控制指针的定义*/
static rt_thread_t bms_iic_thread = RT_NULL;
static rt_thread_t bms_can_thread = RT_NULL;
static rt_thread_t bms_rtc_thread = RT_NULL;
static rt_thread_t bms_wifi_thread = RT_NULL;
static rt_thread_t bms_mqttrecv_thread = RT_NULL;
static rt_thread_t bms_screen_thread = RT_NULL;
static rt_thread_t bms_screen_read_thread = RT_NULL;
static rt_thread_t bms_m4_m7_thread = RT_NULL;
static rt_thread_t bms_data_pack_thread = RT_NULL;
//static rt_thread_t bms_m4_m7_recv_thread = RT_NULL;

/* 信号量、互斥量的定义 */
rt_mutex_t reflash_time_mutex = RT_NULL;// 定义一个动态互斥量控制块指针
rt_mutex_t reflash_state_mutex = RT_NULL;// 定义一个动态互斥量控制块指针
/* 全局变量的定义 */
volatile uint8_t rx_complete = 0; // 收到完整数据的标志
volatile uint8_t rx_complete2 = 0; // 收到完整数据的标志
volatile uint8_t rx_complete3 = 0; // 收到完整数据的标志
volatile uint8_t rx_complete4 = 0; // 收到MQTT断开的指令完整数据的标志
bms_public_pack_data all_content __attribute__((section(".sram4_section")));
uint16_t conmand_send_buf[60] = {0};

/*线程的入口函数
 * @state :
 *
 * */
float ele_data[4] = {0.0, 0.0, 0.0, 0.0};
void iic_data_disposs_entry(void *parameter)
{
	//char buffer[32]={0};
	unsigned char ch = 0;
	float curr_ina = 0.0f;
	float volt_ina = 0.0f;
	INA226_Init();
    while(1)
    {
    	for(ch = 0; ch < 3; ch+=2)
    	{
			curr_ina = (float)(INA226_Read2Byte(Current_Reg, ch)*0.25);
			ele_data[ch] = curr_ina;
			//sprintf(buffer, "Curr %d :%0.2f\r\n", ch, curr_ina);//将浮点转换成字符串；
			//HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 100);
			volt_ina = (float)INA226_Read2Byte(Bus_V_Reg, ch)*1.25;
			ele_data[ch+1] = volt_ina;
			//sprintf(buffer, "Volt %d :%0.2f\r\n", ch, volt_ina);//将浮点转换成字符串；
			//HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 100);
    	}
    	if(ele_data[0] > 3000)
    	{
    		ele_data[0] = 0;
    	}
    	if(ele_data[2] > 3000)
		{
    		ele_data[2] = 0;
		}
    	//HAL_UART_Transmit(&huart2, (uint8_t *)"my is iic thread1", 17, 100);
    	rt_thread_mdelay(500);
    }
}
uint32_t all_ele_wh = 0,all_ele_wh1 = 0;
void can_data_disposs_entry(void *parameter)
{
	uint8_t i = 0;
	/*CAN过滤器配置*/
	Config_FDCAN_Filter();
	rt_thread_mdelay(500);
//	/* 启动 FDCAN 接收中断 */
	if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
		Error_Handler();
	}
    while(1)
    {
		for(i = 0;i < 10;i++)
		{
		  Read_From_Slave1(i);
		  rt_thread_mdelay(30);
		}
		//HAL_UART_Transmit(&huart2, (uint8_t*)"001 is recv end\r\n", 17, 100);
		rt_thread_mdelay(300);
		for(i = 0;i < 10;i++)
		{
		  Read_From_Slave2(i);
		  rt_thread_mdelay(30);
		}
		all_ele_wh = all_ele_wh + (ele_data[0] * ele_data[1]) / 1000 / 1000;
		all_ele_wh1 = all_ele_wh1 + (ele_data[2] * ele_data[3]) / 1000 /1000;
    	//HAL_UART_Transmit(&huart2, (uint8_t*)"002 is recv end\r\n", 17, 100);
    	//HAL_UART_Transmit(&huart2, (uint8_t *)"my is can thread2", 17, 100);
        //rt_thread_mdelay(500);
		rt_thread_mdelay(300);
    }
}

/*RTC时间更新********************************************************************************************/
uint8_t rtc_buf[4] = {0,0,0,0};
RTC_TimeTypeDef sTime = {0};
RTC_DateTypeDef sDate = {0};
char time_store[50] = {0};
char data_store[50] = {0};
uint8_t test_flag = 0;
char time_str[10];//得到网络时间

/*按空格提起时间字符串*/
void extract_sscanf(char *input, char *time_out)
{
    // 格式：+CIPSNTPTIME:Fri May 29 22:21:05 2026
    // 跳过前4个字段（+CIPSNTPTIME:、Fri、May、29），第5个字段就是时间
    int ret = sscanf(input, "%*s %*s %*s %8s %*s", time_out);
    if (ret != 1)
    {
        time_out[0] = '\0';   // 提取失败，置空字符串
        test_flag = 1;//不更新时间
        HAL_UART_Transmit(&huart2, (uint8_t*)"time is error!\r\n", 16, 100);
        //get_time();
    }
}

void data_to_num(void)
{
	if (strstr(data_store, "Mon") != NULL)
	{
	    // 星期一
		sDate.WeekDay = 1;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else if (strstr(data_store, "Tue") != NULL)
	{
	    // 星期二
		sDate.WeekDay = 2;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else if (strstr(data_store, "Wed") != NULL)
	{
	    // 星期三
		sDate.WeekDay = 3;
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
	}
	else if (strstr(data_store, "Thu") != NULL)
	{
	    // 星期四
		sDate.WeekDay = 4;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else if (strstr(data_store, "Fri") != NULL)
	{
	    // 星期五
		sDate.WeekDay = 5;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else if (strstr(data_store, "Sat") != NULL)
	{
	    // 星期六
		sDate.WeekDay = 6;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else if (strstr(data_store, "Sun") != NULL)
	{
	    // 星期日
		sDate.WeekDay = 7;
		HAL_UART_Transmit(&huart2, (uint8_t*)"Date is erefresh!\r\n", 20, 300);
		HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
	else
	{
	    //错误
		HAL_UART_Transmit(&huart2, (uint8_t*)"Data get error!\r\n", 17, 300);
	}
}

uint8_t get_time()
{
	char *str_find;
	if (rt_mutex_take(reflash_time_mutex, RT_WAITING_FOREVER) == RT_EOK)
		HAL_UART_Transmit(&huart2, (uint8_t*)"time get mutex!\r\n", 17, 300);
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\",\"ntp2.aliyun.com\",\"time1.cloud.tencent.com\"\r\n",81 , 200);//设置区域时间
	rt_thread_mdelay(10000);
	memset(dma_process_buffer, 0, strlen((char *)dma_process_buffer));
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+CIPSNTPTIME?\r\n",17 , 200);//设置区域时间
	rt_thread_mdelay(3000);
	if(rx_complete == 1 && strstr((char *)dma_process_buffer, "\n") != NULL)
	{
		rx_complete = 0;
		str_find = strstr((char *)dma_process_buffer, "+CIPSNTPTIME:");
		if(str_find != NULL)
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)"Get time data!\r\n", 16, 300);
			str_find += 13;
			memcpy(time_store, str_find, 19);
			memcpy(data_store, str_find, 3);
			time_store[19] = '\0';
			data_store[3] = '\0';
		}

	   HAL_UART_Transmit(&huart2, (uint8_t*)time_store, 19, 300);
	   HAL_UART_Transmit(&huart2, (uint8_t*)data_store, 3, 300);
	   rt_thread_mdelay(500);
	   test_flag = 0;
	   HAL_UART_Transmit(&huart2, (uint8_t*)"Start Transform\r\n", 17, 300);
	   extract_sscanf(time_store, time_str);// 足够容纳时间字符串
	   HAL_UART_Transmit(&huart2, (uint8_t*)time_str, strlen(time_str), 300);
	   // 处理完毕，务必释放互斥量！
	   rt_mutex_release(reflash_time_mutex);
	   return 1;
	}
	rt_mutex_release(reflash_time_mutex);
	return 1;
}

uint8_t dect_mqtt_connect(void)
{
	char mqtt_state_store[10];
	char *str_find;
	if (rt_mutex_take(reflash_time_mutex, RT_WAITING_FOREVER) == RT_EOK)
			HAL_UART_Transmit(&huart2, (uint8_t*)"dectmqtt get mutex!\r\n", 17, 300);
	//发送检测MQTT连接的命令

	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+MQTTCONN?\r\n",14 , 300);
	rt_thread_mdelay(3000);
	if(strstr((char *)dma_process_buffer, "\n") != NULL)
	{
		//+MQTTCONN:0,4,1,"192.168.123.172","1883","",1
		//+MQTTCONN:
		str_find = strstr((char *)dma_process_buffer, "+MQTTCONN:");
		if(str_find != NULL)
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)"Get mqtt state!\r\n", 17, 300);
			str_find += 12;
			memcpy(mqtt_state_store, str_find, 1);
			mqtt_state_store[1] = '\0';
			HAL_UART_Transmit(&huart2, (uint8_t*)mqtt_state_store, 1, 300);
		}
		if(mqtt_state_store[0] != '0')
		{
			//HAL_UART_Transmit(&huart2, (uint8_t*)mqtt_state_store, 1, 300);
			HAL_UART_Transmit(&huart2, (uint8_t*)"MQTT is connected\r\n", 17, 300);
		}
		else
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)"MQTT is disconnected\r\n", 17, 300);
			HAL_UART_Transmit(&huart3, (uint8_t*)"AT+MQTTCLEAN=0\r\n",16 , 200);
			if(AT_WaitResp("OK", 5000) != 1)
			{
				//超时或没收到
				HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
				rx_complete4  =  1;
			}
			else
			{
				//接收成功
				HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
				rx_complete4  =  0;
			}
			rt_thread_mdelay(1000);
			HAL_UART_Transmit(&huart3, (uint8_t*)"AT+MQTTCONN=0,\"192.168.123.172\",1883,1\r\n",40 , 200);
			if(AT_WaitResp("OK", 5000) != 1)
			{
				//超时
				HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
			}
			else
			{
				//接收成功
				HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
			}
		}
		rt_mutex_release(reflash_time_mutex);
		return 1;
	}
	rt_mutex_release(reflash_time_mutex);
	return 1;
}



void rtc_data_disposs_entry(void *parameter)
{
	//char display_buf[16];
	//启动定时器
	HAL_TIM_Base_Start_IT(&htim2);
    while(1)
    {
    	if(time_flag2 == 1)//定时器5分钟后该标志位置1
		{
		  get_time();
		  time_flag2 = 0;//清除标志位
		}
    	// 获取时间 (时、分、秒)
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		// 获取日期 (年、月、日、星期)
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
		//HAL_UART_Transmit(&huart2, (uint8_t*)time_str, 10, 300);

		if(test_flag == 0 )
		{
			sTime.Hours = (time_str[0]-48) * 10 + (time_str[1]-48);
			sTime.Minutes = (time_str[3]-48) * 10 + (time_str[4]-48);
			sTime.Seconds = (time_str[6]-48) * 10 + (time_str[7]-48);
			data_to_num();
			HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

			HAL_UART_Transmit(&huart2, (uint8_t*)"Time is erefresh!\r\n", 20, 300);
			test_flag = 1;
		}
		rtc_buf[0] = sTime.Hours;
		rtc_buf[1] = sTime.Minutes;
		rtc_buf[2] = sTime.Seconds;
		rtc_buf[3] = sDate.WeekDay;
		//sprintf(display_buf, "%d:%02d:%02d:%02d\r\n", sDate.WeekDay, sTime.Hours, sTime.Minutes, sTime.Seconds);
    	//HAL_UART_Transmit(&huart2, (uint8_t *)display_buf, strlen(display_buf), 100);
//    	HAL_UART_Transmit(&huart2, (uint8_t *)"Is thread3!", 11, 100);
        rt_thread_mdelay(100);
    }
}

/* WIFI 配置 */
char esp_send[256] = {0};
char esp_send1[256] = {0};
char esp_send2[256] = {0};
uint16_t mqtt_len1 = 0, mqtt_len2 = 0, mqtt_len3 = 0;

void MQTT_config(void)
{
	char esp_recv[] = "AT+MQTTSUB=0,\"APP\",0\r\n";
//	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+RESTORE\r\n",12 , 300);
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+RST\r\n", 8, 200);
	rt_thread_mdelay(10000);
	rt_thread_mdelay(10000);
	HAL_UART_Transmit(&huart3, (uint8_t*)"ATE0\r\n", 6, 200);
	if(AT_WaitResp("OK", 5000) != 1)
	{
		//超时
		HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
	}
	else
	{
		//接收成功
		HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
	}
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+CWMODE=1\r\n",13 , 300);
	if(AT_WaitResp("OK", 5000) != 1)
	{
		//超时
		HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
	}
	else
	{
		//接收成功
		HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
	}
	//rt_thread_mdelay(2000);
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+CWJAP=\"Xiaomi_524\",\"12345678\"\r\n",34 , 300);
	rt_thread_mdelay(5000);
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+MQTTUSERCFG=0,1,\"ESP8266-ID\",\"ESP8266UserName\",\"123456\",0,0,\"\"\r\n",67 , 300);
	if(AT_WaitResp("OK", 5000) != 1)
	{
		//超时
		HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
	}
	else
	{
		//接收成功
		HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
	}
	rt_thread_mdelay(4000);
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+MQTTCONN=0,\"192.168.123.172\",1883,1\r\n",40 , 200);
	if(AT_WaitResp("OK", 5000) != 1)
	{
		//超时
		HAL_UART_Transmit(&huart2, (uint8_t*)"T_O\r\n",5 , 200);
	}
	else
	{
		//接收成功
		HAL_UART_Transmit(&huart2, (uint8_t*)"OK\r\n",4 , 200);
	}
	HAL_UART_Transmit(&huart3, (uint8_t*)"AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\",\"ntp2.aliyun.com\",\"time1.cloud.tencent.com\"\r\n",81 , 200);//设置区域时间
	rt_thread_mdelay(4000);
	HAL_UART_Transmit(&huart3, (uint8_t*)esp_recv, sizeof(esp_recv), 300);
	HAL_UART_Transmit(&huart2, (uint8_t*)"5\r\n",5 , 200);
//	/* 开启DMA接收中断 */
	while(HAL_UARTEx_ReceiveToIdle_DMA(&huart3, rx_dmabuffer, sizeof(rx_dmabuffer)-1) != HAL_OK);
	rt_thread_mdelay(2000);
	get_time();
	rt_thread_mdelay(1000);
}

void MQTT_disconnect_config(void)
{

}


void wifi_disposs_entry(void *parameter)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)"Network is Setting", 18, 100);
	MQTT_config();
	HAL_UART_Transmit(&huart2, (uint8_t*)"Network is Success", 18, 100);
	while(1)
	{
		if (rt_mutex_take(reflash_time_mutex, RT_WAITING_FOREVER) == RT_EOK)
			HAL_UART_Transmit(&huart2, (uint8_t*)"mqtt send get mutex!\r\n", 22, 300);
		//HAL_UART_Transmit(&huart2, (uint8_t*)"my is thread4\r\n", 17, 200);

		/* 将数据通过ESP8266上传 */
		if(can_recv_fanish_flag == 1)
		{
			if(((databuf[0]>>16) & 0xff) == 0xff)//负的
			{
				mqtt_len1 = snprintf(esp_send, sizeof(esp_send), "AT+MQTTPUB=0,\"BMS\",\"X:1 Y:1 A:-%d B:%d C:%d D:%d E:%d F:%d G:%d H:%d N:%d O:%d I:1\",0,0\r\n",
						 (-databuf[0]), databuf[1], databuf[2],databuf[3], databuf[4], databuf[5], databuf[6], databuf[7],databuf[8], databuf[9]);
				esp_send[mqtt_len1] = '\0';
			}
			else
			{
				mqtt_len1 = snprintf(esp_send, sizeof(esp_send), "AT+MQTTPUB=0,\"BMS\",\"X:1 Y:1 A:%d B:%d C:%d D:%d E:%d F:%d G:%d H:%d N:%d O:%d I:1\",0,0\r\n",
						  databuf[0], databuf[1], databuf[2],databuf[3], databuf[4], databuf[5], databuf[6], databuf[7],databuf[8], databuf[9]);
				esp_send[mqtt_len1] = '\0';
			}


			if(((databuf2[0]>>16) & 0xff) == 0xff)//负的
			{
				mqtt_len2 = snprintf(esp_send1, sizeof(esp_send1), "AT+MQTTPUB=0,\"BMS\",\"X:1 Y:1 A:-%d B:%d C:%d D:%d E:%d F:%d G:%d H:%d N:%d O:%d I:2\",0,0\r\n",
						(-databuf2[0]), databuf2[1], databuf2[2],databuf2[3], databuf2[4], databuf2[5], databuf2[6], databuf2[7],databuf2[8], databuf2[9]);
				esp_send1[mqtt_len2] = '\0';
			}
			else
			{
				mqtt_len2 = snprintf(esp_send1, sizeof(esp_send1), "AT+MQTTPUB=0,\"BMS\",\"X:1 Y:1 A:%d B:%d C:%d D:%d E:%d F:%d G:%d H:%d N:%d O:%d I:2\",0,0\r\n",
						 databuf2[0], databuf2[1], databuf2[2],databuf2[3], databuf2[4], databuf2[5], databuf2[6], databuf2[7],databuf2[8], databuf2[9]);
				esp_send1[mqtt_len2] = '\0';
			}
		}
		if(rx_complete  !=  1 && rx_complete3  !=  1 && rx_complete4  !=  1 && rx_complete2  !=  1)
		{
			HAL_UART_Transmit(&huart3, (uint8_t*)esp_send, mqtt_len1, 300);
			//继续发送下一个
			rt_thread_mdelay(1000);
			HAL_UART_Transmit(&huart3, (uint8_t*)esp_send1, mqtt_len2, 300);
			//继续发送下一个
			rt_thread_mdelay(1000);
			mqtt_len3 = snprintf(esp_send2, sizeof(esp_send2), "AT+MQTTPUB=0,\"BMS\",\"X:1 Y:1 J:%.2f K:%.2f L:%.2f M:%.2f P:%lu Q:%lu I:3\",0,0\r\n",
					ele_data[1], ele_data[0], ele_data[2], ele_data[3],all_ele_wh,all_ele_wh1);
			esp_send2[mqtt_len3] = '\0';
			HAL_UART_Transmit(&huart3, (uint8_t*)esp_send2, mqtt_len3, 300);
			rt_thread_mdelay(1000);
		}

		rt_thread_mdelay(5000);
		rt_thread_mdelay(5000);
		rt_mutex_release(reflash_time_mutex);
		HAL_UART_Transmit(&huart2, (uint8_t*)"mqtt release mutex!\r\n", 21, 300);
		//rt_thread_yield();   // 主动让出CPU，让同优先级或低优先级线程运行
		rt_thread_mdelay(2000);
		 // 处理完毕，务必释放互斥量！

	}
}

void mqtt_recv_entry(void *parameter)
{
	char rev[27] = {0};
	char *str_find;
	uint8_t price[10];
	int comma_cnt = 0;
	while(1)
	{
		if(time_flag1 == 1)//定时器1分钟后该标志位置1
		{
		  dect_mqtt_connect();
		  time_flag1 = 0;//清除标志位
		}
		//HAL_UART_Transmit(&huart2, (uint8_t*)"my is thread5\r\n", 17, 200);
		if(newdam_msg_flag == 1)
		{
			if(strstr((char *)dma_process_buffer, "+MQTTSUBRECV") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"Recv MQTTSUBRECV\r\n", 18, 100);
				rx_complete3 = 1;
			}
			if(strstr((char *)dma_process_buffer, "WIFI DISCONNECT") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"WIFI DISCONNECT\r\n", 17, 100);
				rx_complete2 = 1;
			}
			if(strstr((char *)dma_process_buffer, "+CIPSNTPTIME") != NULL)
			{

				HAL_UART_Transmit(&huart2, (uint8_t*)"Recv Time\r\n", 11, 100);
				rx_complete = 1;
			}
			//当MQTT断开连接时的代码
			if(strstr((char *)dma_process_buffer, "+MQTTDISCONNECTED") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"Recv MQTT DisConnect\r\n", 22, 200);
				rx_complete4 = 1;
			}
			newdam_msg_flag = 0;
		}

		if(rx_complete3 == 1)
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)"SUB is disposs!\r\n", 17, 100);
			str_find = strstr((char *)dma_process_buffer, "+MQTTSUBRECV");
			if(str_find != NULL)
			{
				memset(rev, 0, sizeof(rev)); // 清空
				while(*str_find != '\0' && comma_cnt < 3)
				{
					if(*str_find == ',')
					{
						comma_cnt++;
						HAL_UART_Transmit(&huart2, (uint8_t*)&comma_cnt, 1, 100);
					}
					str_find++; // 指针后移
				}
				HAL_UART_Transmit(&huart2, (uint8_t*)str_find, 27, 100);
				HAL_UART_Transmit(&huart2, (uint8_t*)"\r\n", 2, 100);
				memcpy(rev, str_find, 27);
				rev[27] = '\0';          // 确保字符串终止
			}

			if(strstr(rev, "0x01") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x01", 15, 100);
				conmand_send_buf[1] = 3;
				usart_scram_write_com(0x02, 0x41, 0x00, 3);
			}
			else if(strstr(rev, "0x02") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x02", 15, 100);
				conmand_send_buf[2] = 3;
				usart_scram_write_com(0x02, 0x42, 0x00, 3);
			}
			else if(strstr(rev, "0x03") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x03", 15, 100);
				conmand_send_buf[3] = 5;
				usart_scram_write_com(0x02, 0x43, 0x00, 5);
			}
			else if(strstr(rev, "0x04") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x04", 15, 100);
				conmand_send_buf[4] = 5;
				usart_scram_write_com(0x02, 0x44, 0x00, 5);
			}
			else if(strstr(rev, "0xf1") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0xf1", 15, 100);
				conmand_send_buf[1] = 4;
				usart_scram_write_com(0x02, 0x41, 0x00, 4);
			}
			else if(strstr(rev, "0xf2") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0xf2", 15, 100);
				conmand_send_buf[2] = 4;
				usart_scram_write_com(0x02, 0x42, 0x00, 4);
			}
			else if(strstr(rev, "0xf3") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0xf3", 15, 100);
				conmand_send_buf[3] = 6;
				usart_scram_write_com(0x02, 0x43, 0x00, 6);
			}
			else if(strstr(rev, "0xf4") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0xf4", 15, 100);
				conmand_send_buf[4] = 6;
				usart_scram_write_com(0x02, 0x44, 0x00,6);
			}
			else if(strstr(rev, "0x05") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x05", 15, 100);
				conmand_send_buf[0] = 8;
				usart_scram_write_com(0x02, 0x45, 0x00, 8);
			}
			else if(strstr(rev, "0x06") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x06", 15, 100);
				conmand_send_buf[0] = 7;
				usart_scram_write_com(0x02, 0x45, 0x00, 7);
			}
			else if(strstr(rev, "0x07") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x07", 15, 100);

			}
			else if(strstr(rev, "0x08") != NULL)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x08", 15, 100);

			}
			else if(strstr(rev, "0x09") != NULL)
			{
				//接收到固定电价的信息
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x09", 15, 100);
				str_find = strstr(rev, "0x09:");
				str_find += 5;
				memcpy(price,str_find,4);
//				float floatValue = atof((char *)price);
//				all_content.firm_price = floatValue;
				HAL_UART_Transmit(&huart2, (uint8_t*)price, 4, 100);
			}
			else if(strstr(rev, "0x10") != NULL)
			{

				//接收到分时电价的信息
				HAL_UART_Transmit(&huart2, (uint8_t*)"command is 0x10", 15, 100);
//				str_find = strstr(rev, "0x10:");
//				str_find += 5;
//				memcpy(price,str_find,4);
//				float floatValue = atof(price);
//				HAL_UART_Transmit(&huart2, (uint8_t*)price, 4, 100);
			}
			rx_complete3 = 0;
			HAL_UARTEx_ReceiveToIdle_DMA(&huart3, rx_dmabuffer, sizeof(rx_dmabuffer)-1);
		}

		if(rx_complete2  ==  1)
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)"Network is disconnect!", 22, 100);
			MQTT_disconnect_config();
			rx_complete2  =  0;
		}

		if(rx_complete4  ==  1)
		{
			rx_complete4 = 0;
		}
		rt_thread_mdelay(100);
	}
}
/***********************************************************************************/
/*串口1驱动屏幕函数
 * *********************************************************************************/
/**
 * 功能描述
 * 参数：input为GBK 字符串指针
 * 参数：in_len为输入字节长度
 * 参数：output为输出缓冲区，保证长度 >= in_len * 2 + 1
 */
void BytesToHexStr(uint8_t *input, uint32_t in_len, uint8_t *output)
{
    const char hex_table[] = "0123456789ABCDEF";
    uint32_t i;
    uint8_t *out = output;

    for (i = 0; i < in_len; i++)
    {
        uint8_t byte = input[i];
        // 高4位
        *out++ = hex_table[(byte >> 4) & 0x0F];
        // 低4位
        *out++ = hex_table[byte & 0x0F];
    }
    *out = '\0';  // 添加字符串结束符
}
/*功能描述
 * ①串口屏幕读取指令
 * ②并接受返回的信息
 * 参数1：长度；参数2：高位地址；参数3：低位地址；参数4：存放接收数据
 * */

void usart_scram_read_com(uint8_t len, uint8_t dar_h, uint8_t dar_l, uint8_t rev[])
{
	uint8_t com[7];
	int i = 0;
	com[0]=0x5A;com[1]=0xA5;com[2]=len + 3;com[3]=0x83;com[4]=dar_h;com[5]=dar_l;com[6]=0x01;
	HAL_UART_Transmit(&huart1, (uint8_t*)com, 7, 100);
	rt_thread_mdelay(100);

	if(recv_flag == 0)
	{
		recv_flag = 1;
		for(i = 0; i < 9; i++)
		{
			rev[i] = buffer[i];
		}
		//HAL_UART_Transmit(&huart2, (uint8_t*)rev, 9, 100);
	}
}

/*功能描述
 * 串口发送指令
 * 更改数字变量地址的内容 */

void usart_scram_write_com(uint8_t len, uint8_t dar_h, uint8_t dar_l, int value)
{
	uint8_t com[10];
	uint8_t data_h = (value >> 8) & 0xFF;
	uint8_t data_l = value & 0xff;
	com[0]=0x5A;com[1]=0xA5;com[2]=len + 3;com[3]=0x82;com[4]=dar_h;com[5]=dar_l;
	com[6]=data_h;com[7]=data_l;
	HAL_UART_Transmit(&huart1, (uint8_t*)com, 8, 100);
	rt_thread_mdelay(100);
}

/*功能描述
 * 串口发送指令
 * 更改文本变量地址的内容 */
void usart_scram_write_com_text(uint8_t len, uint8_t dar_h, uint8_t dar_l, uint8_t *indata)
{
	uint8_t i = 0;
	uint8_t com[100];
	//memcpy(data, indata, strlen((const char*)indata));
	com[0] = 0x5A;com[1]=0xA5;com[2]=len + 3;com[3]=0x82;com[4]=dar_h;com[5]=dar_l;
	for(i=0;i<len;i++)
	{
		com[6+i] = indata[i];
	}
	com[i] = '\0';
	HAL_UART_Transmit(&huart1, (uint8_t*)com, sizeof(com), 100);
	rt_thread_mdelay(100);
}
/* 串口屏幕数据刷新程序  */
char rct_str_buf[20] = {0};
uint32_t current_power = 0;
extern bms_screen_touch_data form_m7_get_context;
void screen_display(void)
{
	//电芯1的总电压的地址1900
	usart_scram_write_com(0x02, 0x19, 0x00, databuf[1]);
	//电芯2的总电压地址2100
	usart_scram_write_com(0x02, 0x21, 0x00, databuf2[1]);
	//充电电流1的地址2000
	usart_scram_write_com(0x02, 0x20, 0x00, databuf[0]);
	//充电电流2的地址2200
	usart_scram_write_com(0x02, 0x22, 0x00, databuf2[0]);
	//电池1的温度地址是4000/1200
	usart_scram_write_com(0x02, 0x40, 0x00, databuf[2]);
	usart_scram_write_com(0x02, 0x12, 0x00, databuf2[2]);

	//电池组1的SOC的地址1600
	usart_scram_write_com(0x02, 0x16, 0x00, databuf[8]);
	//电池组1的SOH的地址是1700
	usart_scram_write_com(0x02, 0x17, 0x00, databuf[9]);
	//电池组2的SOC的地址5600
	usart_scram_write_com(0x02, 0x56, 0x00, databuf2[8]);
	//电池组2的SOH的地址是5700
	usart_scram_write_com(0x02, 0x57, 0x00, databuf2[9]);

	//电芯1的电压地址2700；电芯2的电压地址2800；电芯3的电压地址2900；电芯4的电压地址3000；电芯5的电压地址3100；电芯1的电压地址3200；
	usart_scram_write_com(0x02, 0x27, 0x00, databuf[3]);
	usart_scram_write_com(0x02, 0x28, 0x00, databuf[4]);
	usart_scram_write_com(0x02, 0x29, 0x00, databuf[5]);
	usart_scram_write_com(0x02, 0x30, 0x00, databuf[6]);
	usart_scram_write_com(0x02, 0x31, 0x00, databuf[7]);
	//电芯1的电压地址3300；电芯2的电压地址3400；电芯3的电压地址3500；电芯4的电压地址3600；电芯5的电压地址3700；电芯1的电压地址3800；
	usart_scram_write_com(0x02, 0x33, 0x00, databuf2[3]);
	usart_scram_write_com(0x02, 0x34, 0x00, databuf2[4]);
	usart_scram_write_com(0x02, 0x35, 0x00, databuf2[5]);
	usart_scram_write_com(0x02, 0x36, 0x00, databuf2[6]);
	usart_scram_write_com(0x02, 0x37, 0x00, databuf2[7]);

	if(conmand_send_buf[5] == 22)
	{
		//电网显示
		usart_scram_write_com(0x02, 0x48, 0x00, ele_data[1]);//电压
		usart_scram_write_com(0x02, 0x49, 0x00, ele_data[0]);//电流
	}
	else if(conmand_send_buf[6] == 24)
	{
		//光伏显示
		usart_scram_write_com(0x02, 0x48, 0x00, ele_data[3]);//电压
		usart_scram_write_com(0x02, 0x49, 0x00, ele_data[2]);//电流
	}

	if(form_m7_get_context.dischg1_state == 1 && ((databuf[0]>>16) & 0xff) == 0xff)
	{
		//当前负荷的地址：5200
		current_power = ((-1)*databuf[0] * databuf[1])/10000;
		usart_scram_write_com(0x02, 0x52, 0x00, current_power);
		//未来1小时的负荷地址：5300
		usart_scram_write_com(0x02, 0x53, 0x00, form_m7_get_context.bms_future_load * 100);
	}
	else if(form_m7_get_context.dischg2_state == 1 && ((databuf2[0]>>16) & 0xff) == 0xff)
	{
		//当前负荷的地址：5200
		current_power = ((-1)*databuf2[0] * databuf2[1])/10000;
		usart_scram_write_com(0x02, 0x52, 0x00, current_power);
		//未来1小时的负荷地址：5300
		usart_scram_write_com(0x02, 0x53, 0x00, form_m7_get_context.bms_future_load * 100);
	}
	else
	{
		//当前负荷的地址：5200
		current_power = 0;
		usart_scram_write_com(0x02, 0x52, 0x00, current_power);
		//未来1小时的负荷地址：5300
		usart_scram_write_com(0x02, 0x53, 0x00, form_m7_get_context.bms_future_load * 100);
	}
	//时间显示的地址1000；
	snprintf(rct_str_buf, sizeof(rct_str_buf), "%02d: %02d: %02d: %02d",rtc_buf[3], rtc_buf[0], rtc_buf[1], rtc_buf[2]);
	usart_scram_write_com_text(sizeof(rct_str_buf)+3, 0x10, 0x00, (uint8_t *)rct_str_buf);

}


void screen_touch_return(void)
{
	uint8_t com_len = 0;
	uint8_t rev1[32];

	usart_scram_read_com(0x01,0x45,0x00,rev1);//手动模式和自动模式
	conmand_send_buf[com_len++] = rev1[8];//[ 7 / 8]

	usart_scram_read_com(0x01,0x41,0x00,rev1);//电池1号充电信号
	conmand_send_buf[com_len++] = rev1[8];//[ 3 / 4]

	usart_scram_read_com(0x01,0x42,0x00,rev1);//电池2号充电信号
	conmand_send_buf[com_len++] = rev1[8];//[ 3 / 4]

	usart_scram_read_com(0x01,0x43,0x00,rev1);//电池1号放电信号
	conmand_send_buf[com_len++] = rev1[8];//[ 5 / 6]

	usart_scram_read_com(0x01,0x44,0x00,rev1);//电池2号放电信号
	conmand_send_buf[com_len++] = rev1[8];//[ 5 / 6]

	usart_scram_read_com(0x01,0x46,0x00,rev1);//电网有效信号
	conmand_send_buf[com_len++] = rev1[8];//[21 / 22]

	usart_scram_read_com(0x01,0x47,0x00,rev1);//光伏有效信号
	conmand_send_buf[com_len++] = rev1[8];//[23 / 24]

	usart_scram_read_com(0x01,0x14,0x00,rev1);//电池1风扇信号
	conmand_send_buf[com_len++] = rev1[8];//[0~10]

	usart_scram_read_com(0x01,0x15,0x00,rev1);//电池2风扇信号
	conmand_send_buf[com_len++] = rev1[8];//[0~10]

	usart_scram_read_com(0x01,0x11,0x00,rev1);//设置的温度
	conmand_send_buf[com_len++] = rev1[7] << 8 | rev1[8] ;//最小设定的温度是20摄氏度

	conmand_send_buf[com_len] = '\0';
	//HAL_UART_Transmit(&huart2, (uint8_t*)conmand_send_buf, com_len, 100);
}
void usart_screen_entry(void *parameter)
{
	while(1)
	{
		screen_display();
		rt_thread_mdelay(100);
	}
}

/********串口屏幕读取线程******************************************************************************/

void usart_screen_read_entry(void *parameter)
{
	HAL_UART_Receive_IT(&huart1, &rx_data, 1);
	while(1)
	{
		screen_touch_return();
		//HAL_UART_Transmit(&huart2, (uint8_t *)"Screen is read successful!\r\n", 28, 100);
		rt_thread_mdelay(100);
	}
}
/*******数据打包线程********************************************************************/
//电池组1、2的信息
//串口屏幕的信息
//uint8_t all_content[512] = {0};



void bms_data_pack_entry(void *parameter)
{

	while(1)
	{
		all_content.gridi = ele_data[0];
		all_content.gridv = ele_data[1];
		all_content.solori = ele_data[2];
		all_content.solorv = ele_data[3];

		all_content.bms_battery_i = databuf[0];
		all_content.bms_battery_v = databuf[1];
		all_content.bms_battery_t = databuf[2];
		all_content.bms_battery_v1 = databuf[3];
		all_content.bms_battery_v2 = databuf[4];
		all_content.bms_battery_v3 = databuf[5];
		all_content.bms_battery_v4 = databuf[6];
		all_content.bms_battery_v5 = databuf[7];
		all_content.soc_1 = databuf[8];
		all_content.bms_battery_power = current_power/100;

		all_content.bms_battery2_i = databuf2[0];
		all_content.bms_battery2_v = databuf2[1];
		all_content.bms_battery2_t = databuf2[2];
		all_content.bms_battery2_v1 = databuf2[3];
		all_content.bms_battery2_v2 = databuf2[4];
		all_content.bms_battery2_v3 = databuf2[5];
		all_content.bms_battery2_v4 = databuf2[6];
		all_content.bms_battery2_v5 = databuf2[7];
		all_content.soc_2 = databuf2[8];
		all_content.bms_battery2_power = current_power/100;

		all_content.Mode = conmand_send_buf[0];
		all_content.charge1 = conmand_send_buf[1];
		all_content.charge2 = conmand_send_buf[2];
		all_content.discharge1 = conmand_send_buf[3];
		all_content.discharge2 = conmand_send_buf[4];
		all_content.grid_ctl = conmand_send_buf[5];
		all_content.solor_ctl = conmand_send_buf[6];
		all_content.fan1_ctl = conmand_send_buf[7];
		all_content.fan2_ctl = conmand_send_buf[8];
		all_content.bms_set_temp = conmand_send_buf[9];

		all_content.bms_date = rtc_buf[3];
		all_content.bms_hour = rtc_buf[2];
		all_content.bms_minutes = rtc_buf[1];
		all_content.bms_seconds = rtc_buf[0];

		//HAL_UART_Transmit(&huart2, (uint8_t *)all_content,strlen((char*)all_content) , 300);
		//HAL_UART_Transmit(&huart2, (uint8_t *)"data pack is successful!\r\n", 26, 100);
		rt_thread_mdelay(500);
	}
}



/* ********************向M7内核进行信息上传******************************************** */
/*首先定义RP服务器消息*/
#define RPMSG_SERVICE_NAME "openamp_test"
#define MAX_STR_LEN 512   // 根据实际定义修改
uint32_t message_m4 = 15;					//要发送的消息
static volatile int message_received;       //接收消息标志位
unsigned char received_data_str[MAX_STR_LEN];//接收数据变量
static struct rpmsg_endpoint rp_endpoint;   //定义一个RP的端点点
char data[100];								//作为字符串的转换接收
int32_t status = 0;
bms_screen_touch_data form_m7_get_context __attribute__((section(".sram4_section")));

int rpmsg_recv_callback(struct rpmsg_endpoint *ept, void *data, size_t len, uint32_t src, void *priv)
{
	size_t copy_len = (len < MAX_STR_LEN - 1) ? len : MAX_STR_LEN - 1;
	// 复制数据到字符数组
	memcpy(&form_m7_get_context, data, copy_len);
    message_received=1;
    return 0;
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


void fan_return (uint8_t fan_q, uint8_t addr)
{
	switch(fan_q)
	{
		case 1:
			usart_scram_write_com(0x02, addr, 0x00, 1);
			break;
		case 2:
			usart_scram_write_com(0x02, addr, 0x00, 2);
			break;
		case 3:
			usart_scram_write_com(0x02, addr, 0x00, 3);
			break;
		case 4:
			usart_scram_write_com(0x02, addr, 0x00, 4);
			break;
		case 5:
			usart_scram_write_com(0x02, addr, 0x00, 5);
			break;
		case 6:
			usart_scram_write_com(0x02, addr, 0x00, 6);
			break;
		case 7:
			usart_scram_write_com(0x02, addr, 0x00, 7);
			break;
		case 10:
			usart_scram_write_com(0x02, addr, 0x00, 10);
			break;
	}
}

void button_return(uint8_t number, uint8_t addr, uint8_t var_y,uint8_t var_n)
{
	if(number == 0)
	{
		usart_scram_write_com(0x02, addr, 0x00, var_n);
	}
	else
	{
		usart_scram_write_com(0x02, addr, 0x00, var_y);
	}
}



void bms_msg_m7andm4(void *parameter)
{
	static uint8_t last_state[10] = {0};
	//初始化邮箱
	MAILBOX_Init();
	//初始化OpenAmp看是否正常
	if (MX_OPENAMP_Init (RPMSG_REMOTE, NULL)!= HAL_OK)
		Error_Handler();
	//为 rmpsg 通信创建一个端点
	status = OPENAMP_create_endpoint (&rp_endpoint, RPMSG_SERVICE_NAME, RPMSG_ADDR_ANY, rpmsg_recv_callback, NULL);
	if (status<0)
	{
		Error_Handler();
	}

	while(1)
	{
		receive_message ();
		if(form_m7_get_context.requst == 'A')
		{
			status = OPENAMP_send(&rp_endpoint, &all_content, sizeof(all_content));
			if (status < 0)
			{
				Error_Handler();
			}
			rt_thread_mdelay(100);
		}
		if(conmand_send_buf[0] == 8)//自动模式
		{
			fan_return(form_m7_get_context.fan1_state,0x15);
			fan_return(form_m7_get_context.fan2_state,0x14);
			button_return(form_m7_get_context.chg1_state,0x41,3,4);
			button_return(form_m7_get_context.chg2_state,0x42,3,4);
			button_return(form_m7_get_context.dischg1_state,0x43,5,6);
			button_return(form_m7_get_context.dischg2_state,0x44,5,6);
			button_return(form_m7_get_context.grid_state,0x46,22,21);
			button_return(form_m7_get_context.solor_state,0x47,24,23);
		}
		else
		{
			if(last_state[0] != form_m7_get_context.solor_state)
			{
				button_return(form_m7_get_context.solor_state,0x47,24,23);
				last_state[0] = form_m7_get_context.solor_state;
			}
			if(last_state[1] != form_m7_get_context.grid_state)
			{
				button_return(form_m7_get_context.grid_state,0x46,22,21);
				last_state[1] = form_m7_get_context.grid_state;
			}
//			button_return(form_m7_get_context.chg1_state,0x41,3,4);
//			button_return(form_m7_get_context.chg2_state,0x42,3,4);
			if(last_state[4] != form_m7_get_context.dischg1_state)
			{
				button_return(form_m7_get_context.dischg1_state,0x43,5,6);
				last_state[4] = form_m7_get_context.dischg1_state;
			}
			if(last_state[5] != form_m7_get_context.dischg2_state)
			{
				button_return(form_m7_get_context.dischg2_state,0x44,5,6);
				last_state[5] = form_m7_get_context.dischg2_state;
			}
		}
		rt_thread_mdelay(100);
	}
}

/**********M7内核传过来的消息解析判断*************/









/* *****************************线程初始化函数************************************************** */
void BMS_rtt_signal(void)
{
	reflash_time_mutex = rt_mutex_create("wifi_mtx", RT_IPC_FLAG_PRIO);
	if (reflash_time_mutex == RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"Mutex error!\r\n", 14, 100);
	}
	else
		HAL_UART_Transmit(&huart2, (uint8_t *)"Mutex successful!\r\n", 19, 100);

	reflash_state_mutex = rt_mutex_create("state_mtx", RT_IPC_FLAG_PRIO);
		if (reflash_state_mutex == RT_NULL)
		{
			HAL_UART_Transmit(&huart2, (uint8_t *)"Mutex error!\r\n", 14, 100);
		}
		else
			HAL_UART_Transmit(&huart2, (uint8_t *)"Mutex successful!\r\n", 19, 100);


}




void MX_rtt_init(void)
{
	/* 相关信号的创建  */
	BMS_rtt_signal();

	/* IIC线程的动态创建  */
	bms_iic_thread = rt_thread_create("bms_iic",           // 线程名字
										iic_data_disposs_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										1024,                // 栈大小（单位：字节）
										10,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread1 is creating!\r\n", 24, 100);
	if (bms_iic_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread1 successful!", 19, 100);
		rt_thread_startup(bms_iic_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread1 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/

	/* can线程的动态创建  */
	bms_can_thread = rt_thread_create("bms_can",           // 线程名字
										can_data_disposs_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										2048,                // 栈大小（单位：字节）
										9,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread2 is creating!\r\n", 24, 100);
	if (bms_can_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread2 successful!", 19, 100);
		rt_thread_startup(bms_can_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread2 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/
	/* can线程的动态创建  */
	bms_rtc_thread = rt_thread_create("bms_rtc",           // 线程名字
										rtc_data_disposs_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										4096,                // 栈大小（单位：字节）
										13,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread3 is creating!\r\n", 24, 100);
	if (bms_rtc_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread3 successful!", 19, 100);
		rt_thread_startup(bms_rtc_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread3 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/

	/* mqtt上传线程的动态创建  */
	bms_wifi_thread = rt_thread_create("bms_wifi",           // 线程名字
										wifi_disposs_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										2048,                // 栈大小（单位：字节）
										14,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread4 is creating!\r\n", 24, 100);
	if (bms_wifi_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread4 successful!", 19, 100);
		rt_thread_startup(bms_wifi_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread4 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/
	/* mqtt接收线程的动态创建  */
	bms_mqttrecv_thread = rt_thread_create("bms_mqtt",           // 线程名字
										mqtt_recv_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										1024,                // 栈大小（单位：字节）
										16,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread5 is creating!\r\n", 24, 100);
	if (bms_mqttrecv_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread5 successful!", 19, 100);
		rt_thread_startup(bms_mqttrecv_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread5 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/

	/* 屏幕驱动写数据线程的动态创建  */
	bms_screen_thread = rt_thread_create("bms_screen",           // 线程名字
										usart_screen_entry,     // 线程入口函数
										RT_NULL,             // 传入参数
										1024,                // 栈大小（单位：字节）
										17,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread6 is creating!\r\n", 24, 100);
	if (bms_screen_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread6 successful!", 19, 100);
		rt_thread_startup(bms_screen_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread6 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/

	/* 屏幕驱动线程的动态创建  */
	bms_screen_read_thread = rt_thread_create("bms_screen_read",       // 线程名字
										usart_screen_read_entry,  // 线程入口函数
										RT_NULL,             // 传入参数
										1024,                // 栈大小（单位：字节）
										18,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread7 is creating!\r\n", 24, 100);
	if (bms_screen_read_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread7 successful!", 19, 100);
		rt_thread_startup(bms_screen_read_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread7 error!", 14, 100);
		Error_Handler();
	}

	/**************************************************************************/

	/* M7与M4核通讯线程的动态创建  */
	bms_m4_m7_thread = rt_thread_create("bms_m4_m7_msg",       // 线程名字
										bms_msg_m7andm4,  // 线程入口函数
										RT_NULL,             // 传入参数
										8192,                // 栈大小（单位：字节）
										20,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread8 is creating!\r\n", 24, 100);
	if (bms_m4_m7_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread8 successful!", 19, 100);
		rt_thread_startup(bms_m4_m7_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread8 error!", 14, 100);
		Error_Handler();
	}
	/**************************************************************************/
	/* 数据打包的动态创建  */
	bms_data_pack_thread = rt_thread_create("bms_data_pack_msg",       // 线程名字
										bms_data_pack_entry,  // 线程入口函数
										RT_NULL,             // 传入参数
										2048,                // 栈大小（单位：字节）
										19,                  // 优先级
										20);                 // 时间片
	HAL_UART_Transmit(&huart2, (uint8_t *)"thread9 is creating!\r\n", 24, 100);
	if (bms_data_pack_thread != RT_NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread9 successful!", 19, 100);
		rt_thread_startup(bms_data_pack_thread);
	}
	else
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"thread9 error!", 14, 100);
		Error_Handler();
	}


	/**************************************************************************/
//	/* M7传过来的数据打包的动态创建  */
//	bms_m4_m7_recv_thread = rt_thread_create("bms_m7_msg_disposs",       // 线程名字
//										bms_msg_m7_disposs,  // 线程入口函数
//										RT_NULL,             // 传入参数
//										1024,                // 栈大小（单位：字节）
//										21,                  // 优先级
//										20);                 // 时间片
//	HAL_UART_Transmit(&huart2, (uint8_t *)"thread10 is creating!\r\n", 24, 100);
//	if (bms_m4_m7_recv_thread != RT_NULL)
//	{
//		HAL_UART_Transmit(&huart2, (uint8_t *)"thread10 successful!", 19, 100);
//		rt_thread_startup(bms_m4_m7_recv_thread);
//	}
//	else
//	{
//		HAL_UART_Transmit(&huart2, (uint8_t *)"thread10 error!", 14, 100);
//		Error_Handler();
//	}

}



