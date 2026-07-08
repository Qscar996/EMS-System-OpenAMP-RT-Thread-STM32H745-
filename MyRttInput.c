#include "MyRttInput.h"
#include "bq40z80.h"
#include "lcd.h"
#include "Myfunction.h"
#include "Myiic.h"
#include "string.h"

/* 定义线程控制块指针 */
rt_thread_t oled_q = RT_NULL;
rt_thread_t iic_data_q = RT_NULL;
rt_thread_t can_slave_q = RT_NULL;

/* 定义互斥量控制块 */
rt_mutex_t mux_q = RT_NULL;

/*
* 定义全局变量
*
*/



/* 延时函数 */
void application_delay(u16 ms)
{
	int i = 0,j = 0;
	for(i = 0;i < 150; i++)
		for(j = 0;j < ms; j++);
}


/* IIC通讯线程入口函数(互斥量) */
void iic_thread_entry(void* parameter)
{ 	
		
		rt_err_t mux_take_Ret = RT_EOK;
		rt_err_t mux_release_Ret = RT_EOK;
		IIC_Init();
		/* 线程都是一个无限循环，不能返回 */
    while (1) 
		{ 
			mux_take_Ret = rt_mutex_take(mux_q,       				/* 获取信号量 */
                  RT_WAITING_FOREVER); 	/* 等待时间：一直等 */
			if(RT_EOK == mux_take_Ret)
				//rt_kprintf ( "send得到互斥量\n" );
			/***/
			
			BQ_DATA_DEAL();
			
			
				//rt_kprintf ( "我在IIC\n" );
			/***/
      mux_release_Ret = rt_mutex_release(mux_q);    			//释放二值信号量
			if(mux_release_Ret == RT_EOK){}
				//rt_kprintf ( "send以释放互斥量\n" );
      rt_thread_delay ( 500 );     //每1s读一次
			rt_thread_yield();              //放弃剩余时间片，进行一次线程切换	
    }
}


/* OLED屏幕刷新程序（互斥量） */
void oled_thread_entry(void* parameter)
{
	
		rt_err_t sem_take_Ret = RT_EOK;
		rt_err_t sem_release_Ret = RT_EOK;

    /* 线程都是一个无限循环，不能返回 */
		LCD_Init();
		LCD_Clear(WHITE); //清屏
    while (1) 
		{
			sem_take_Ret = rt_mutex_take(mux_q,               	/* 获取信号量 */
																 RT_WAITING_FOREVER); 	/* 等待时间：一直等 */
			if(RT_EOK == sem_take_Ret)
				//rt_kprintf ( "rev得到互斥量\n" );
			/***/
			logic();
			//rt_kprintf ( "我在线程OLED\n" );
			rt_thread_delay ( 1000 );     //每1s读一次
			/***/
			
			
      sem_release_Ret = rt_mutex_release(mux_q);   		//释放二值信号量
			if(sem_release_Ret == RT_EOK){}
//			rt_kprintf ( "rev以释放互斥量\n" );
      rt_thread_yield();              //放弃剩余时间片，进行一次线程切换
    }
}



extern uint8_t canrecvflag;

CanRxMsg RxMessage;
extern uint8_t can_rx_buffer[8];
uint16_t jump = 0;
void can_slave_entry(void* parameter)
{
	//RCC_ClocksTypeDef get_clocks;
	uint8_t voltbuf[2] = {0},tempbuf[2] = {0},cell1buf[2] = {0},cell2buf[2] = {0},cell3buf[2] = {0};
	uint8_t currentbuf[2] = {0},cell4buf[2] = {0},cell5buf[2] = {0};
	uint8_t socbuf[2] = {0}, sohbuf[2] = {0};
	//u8 ret=0;
	CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);//CAN初始化正常模式,波特率500Kbps
	while(1)
	{
		//memcpy(can_rx_buffer, RxMessage.Data, 8);
		//Can_Receive_Msg(can_rx_buffer);
		//将16位的数据都转换成大端模式，高8位和低8位；
		currentbuf[0]= (current >> 8) & 0xFF;
		currentbuf[1]=	current & 0xFF;
		voltbuf[0]=	(voltage >> 8)& 0xFF;
		voltbuf[1]=	voltage & 0xFF;
		
		tempbuf[0]= (batt_temp >> 8) & 0xFF;
		tempbuf[1]=	batt_temp & 0xFF;
		
		cell1buf[0]=	(Cell1Voltage >> 8)& 0xFF;
		cell1buf[1]=	Cell1Voltage & 0xFF;
		
		cell2buf[0]= (Cell2Voltage >> 8) & 0xFF;
		cell2buf[1]=	Cell2Voltage & 0xFF;
		
		cell3buf[0]=	(Cell3Voltage >> 8)& 0xFF;
		cell3buf[1]=	Cell3Voltage & 0xFF;
		
		cell4buf[0]= (Cell4Voltage >> 8) & 0xFF;
		cell4buf[1]=	Cell4Voltage & 0xFF;
		
		cell5buf[0]=	(Cell5Voltage >> 8)& 0xFF;
		cell5buf[1]=	Cell5Voltage & 0xFF;
		
		socbuf[0]=	(clc_soc >> 8)& 0xFF;
		socbuf[1]=	clc_soc & 0xFF;

		sohbuf[0]=	(clc_soh >> 8)& 0xFF;
		sohbuf[1]=	clc_soh & 0xFF;
		
		if(canrecvflag == 1)
		{
			jump ++;
			switch(can_rx_buffer[0])
			{
				case 0x01 :Can_Send_Msg(currentbuf,2);break;
				case 0x02 :Can_Send_Msg(voltbuf,2);break;
				case 0x03 :Can_Send_Msg(tempbuf,2);break;
				case 0x04 :Can_Send_Msg(cell1buf,2);break;
				case 0x05 :Can_Send_Msg(cell2buf,2);break;
				case 0x06 :Can_Send_Msg(cell3buf,2);break;
				case 0x07 :Can_Send_Msg(cell4buf,2);break;
				case 0x08 :Can_Send_Msg(cell5buf,2);break;
				case 0x09 :Can_Send_Msg(socbuf,2);break;
				case 0x0A :Can_Send_Msg(sohbuf,2);break;				
			}
			rt_kprintf("收到数据rxbuf[0]:%d\r\n",can_rx_buffer[0]);	
			canrecvflag = 0;
		}
		if(jump == 10)
		{
			rt_kprintf ( "数据发送完成\n" );
			jump = 0;
		}
	
		rt_thread_delay ( 100 ); 	
	}
	
}







