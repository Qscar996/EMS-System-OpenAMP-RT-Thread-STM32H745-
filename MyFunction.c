#include "MyFunction.h"
#include "bq40z80.h"
#include "lcd.h"


uint8_t datad[32];
char display_flag = 1;


extern u8 Key1_Pressed ;
extern u8 Key2_Pressed ;
extern u8 Key3_Pressed ;

void BQ_DATA_DEAL(void)
{
	BQ_Get_TS1_Temp();
	BQ_Get_Volt();
	BQ_Get_Current();
	BQ_Get_Capacity();
//	BQ_Get_Soh();
//	BQ_Get_Soc();
	BQ_Get_full_cap();
	BQ_Get_retain_cap();
	BQ_Get_Cell_1_4_Volt();
	BQ_Get_Cell_5_6_Volt();
	
	//计算SOC
	clc_soc = (retain_cap * 100 / full_cap) ;
	clc_soh = full_cap * 100 / 1800;
}


/* 显示电池组的信息 */
void layout1(void)
{
		//LCD_Clear(WHITE); //清屏
		LCD_ShowString(0,0,LCD_X,24,24,BLACK,"TEMP:");
		LCD_ShowNum(60,0,batt_temp,3,24,RED);
		//Draw_Font16B(12,24,RED,"大越创新");
		LCD_ShowString(0,24,LCD_X,24,24,BLACK,"Volt:");
		LCD_ShowNum(60,24,voltage,5,24,RED);
		
		LCD_ShowString(0,48,LCD_X,24,24,BLACK,"Cap:");
		LCD_ShowNum(60,48,cap,3,24,RED);
	
		if(((current >> 16) & 0xff) == 0xff)//得到负数
	  {
			LCD_ShowString(0,72,LCD_X,24,24,BLACK,"I:");
			LCD_ShowNum(60,72,-current,5,24,GREEN);

		}
		else//得到正数
		{
			LCD_ShowString(0,72,LCD_X,24,24,BLACK,"I: ");
			LCD_ShowNum(60,72,current,5,24,RED);

		}
		
		LCD_ShowString(0,96,LCD_X,24,24,RED,"SOC: ");
		LCD_ShowNum(60,96,clc_soc,3,24,BLUE);
		
		LCD_ShowString(0,120,LCD_X,24,24,RED,"SOH: ");
		LCD_ShowNum(60,120,clc_soh,3,24,BLUE);
}

/* 显示电芯的信息 */
void layout2(void)
{
		//LCD_Clear(WHITE); //清屏
		LCD_ShowString(0,0,LCD_X,16,16,BLACK,"Cell1V:");
		LCD_ShowNum(80,0,Cell1Voltage,4,16,RED);
		
		LCD_ShowString(0,16,LCD_X,16,16,BLACK,"Cell2V:");
		LCD_ShowNum(80,16,Cell2Voltage,4,16,RED);
		
		LCD_ShowString(0,32,LCD_X,16,16,BLACK,"Cell3V:");
		LCD_ShowNum(80,32,Cell3Voltage,4,16,RED);
		
		LCD_ShowString(0,48,LCD_X,16,16,BLACK,"Cell4V:");
		LCD_ShowNum(80,48,Cell4Voltage,4,16,RED);
		
		LCD_ShowString(0,64,LCD_X,16,16,BLACK,"Cell5V:");
		LCD_ShowNum(80,64,Cell5Voltage,4,16,RED);
	
		LCD_ShowString(0,80,LCD_X,16,16,BLACK,"Cell6V:");
		LCD_ShowNum(80,80,Cell6Voltage,4,16,RED);
	
		LCD_ShowString(0,125,LCD_X,24,16,BLUE,"Battery cell information");
}



void logic(void)
{
	if(Key1_Pressed == 1)
	{	
		Key1_Pressed = 0;
		display_flag = 2;
		LCD_Clear(WHITE); //清屏
	}	
	
	if(Key3_Pressed == 1)	 //按键KEY1
	{	
		Key3_Pressed = 0;
		display_flag=1;
		LCD_Clear(WHITE); //清屏
	}
	
		switch(display_flag)
		{
			case 1:
			{
				layout1();
				break;
			}
			case 2:
			{
				layout2();
				break;
			}
		}
	
}

