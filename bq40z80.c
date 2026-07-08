#include "bq40z80.h"
#include "MyTIMDelay.h"

#define TIME 10




//static void delay_us(uint32_t us)
//{
//	uint32_t i, j;
//	// 这个循环次数需要根据你的 CPU 时钟频率精确校准
//	// 这里只是个示意，实际数值需要测试确定
//	for (i = 0; i < us; i++)
//	{
//			for (j = 0; j < 10; j++) // 内循环消耗一定时间
//			{
//					__NOP(); // NOP 指令，空操作，消耗一个时钟周期
//									 // 有时也直接用空循环体 ;
//			}
//	}
//}


uint8_t Recv[60];
uint16_t voltage				= 0;
uint16_t temp						= 0;
uint16_t batt_temp		= 0;
uint16_t cap						= 0;
uint16_t retain_cap			= 0;
uint16_t full_cap						= 0;
uint16_t soc						= 0;
uint16_t soh						= 0;
int16_t  current        = 0;
uint16_t Cell1Voltage		= 0;
uint16_t Cell2Voltage		= 0;
uint16_t Cell3Voltage		= 0;
uint16_t Cell4Voltage		= 0;
uint16_t Cell5Voltage		= 0;
uint16_t Cell6Voltage		= 0;
int32_t clc_soc = 0;
int32_t clc_soh = 0;

/*	CRC-8效验 X8+X2+X+1	*/
/** 实现标准CRC-8算法：使用多项式0x07*/
/** CRC校验是数据发过来会带一些校验值，因此本次是将计算的校验值和数据的校验值是否一致，一致没问题*/
uint8_t calculate_crc8(uint8_t InitialValue, uint8_t *message ,uint8_t len)		
{
	/*传入CRC的初值?，BQ40Z80协议中通常为0x00*/
	uint8_t i, crc = InitialValue;		
	/*遍历每一个字节*/
	while(len--)
	{
		/*message为指向待校验数据的指针*/
		/*当前字节与CRC异或*/
		crc ^= (*message++);
		for(i = 0;i < 8;i++)
		{
			/*看最高位是否为1，因此在循环*/
			if(crc & 0x80)
			{
				crc = (crc << 1) ^ 0x07;		//多项式 POLY
			}
			else crc <<= 1;
		}
	}
	return crc;
}



u8 BQ40Z80_ReadData(uint8_t reg_addr, uint8_t* data, uint8_t len)
{
		int i;
		data[0] = BQ40Z80_ADDR;
		data[1] = reg_addr;
		data[2] = BQ40Z80_ADDR + 1;
		data[3] = 0;
		data[4] = 0;
		data[5] = 0;
		
    // 发送起始条件
    IIC_Start();
    // 发送设备地址
    IIC_Send_Byte(BQ40Z80_ADDR);
    if(IIC_Wait_Ack() == 1)
		{			
			IIC_Stop();
			//printf("cuowu1\r\n");
			return 1;
		}
		
    // 发送要读取的寄存器地址
    IIC_Send_Byte(reg_addr);
		delay_us(80);

	
		//在start之前需要有一个时钟信号，SDA=0
    IIC_SDA_0;
    delay_us(1);
    IIC_SCL_1;
    delay_us(9);
    IIC_SCL_0;
    delay_us(9);
		
		
		//重新发送起始条件
    IIC_Start();
    
    // 发送设备地址（读模式）
    IIC_Send_Byte(BQ40Z80_ADDR + 1);
		if(IIC_Wait_Ack() == 1)
		{	
			//printf("cuowu3\r\n");
			IIC_Stop();
			return 1;
		}
		
		delay_us(58);
		for(i = 3; i < len + 4; i++)
		{	
			data[i] = IIC_Read_Byte(0);
			delay_us(200);
		}		
		

		delay_us(58);                               
    IIC_Stop();

		return 0;
		
		
}


//读取电压
u8 BQ_Get_Volt(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x09, Recv, 2);
	//printf("%d\r\n",err);
	if(err == 0)
	{
		voltage = Recv[4]<<8 | Recv[3];
		//printf("Voltage is :%d\r\n",voltage);
	}
	return voltage;
}

//读取温度
u8 BQ_Get_Temp(void)
{
	int err=0;
	
	err = BQ40Z80_ReadData(0x08, Recv, 2);
	//printf("%d\r\n",err);
	if(err == 0)
	{
		temp = (int16_t)(Recv[4]<<8 | Recv[3]) - 2731.5;
		//printf("TEMP is :%d\r\n",temp);
	}

	return temp;
}


//读取电流
int BQ_Get_Current(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x0A, Recv, 2);
	//printf("%d\r\n",err);
	if(err == 0)
	{
			current = (Recv[4]<<8 | Recv[3]);
	}
	return current;
}




//读取相对SOC
u8 BQ_Get_Capacity(void)
{
	int err=0; 
	err = BQ40Z80_ReadData(0x0D, Recv, 2);
	if(err == 0)
	{
		if((Recv[4]<<8 | Recv[3]) <= 100)
			cap = (Recv[4]<<8 | Recv[3]);
		//printf("Capacity is :%d\r\n",cap);
	}
	return cap;
}





//读取SOH
u8 BQ_Get_Soh(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x4F, Recv, 2);
	if(err == 0)
	{
		if((Recv[4]<<8 | Recv[3]) <= 100)
			soh = (Recv[4]<<8 | Recv[3]);
		//printf("Capacity is :%d\r\n",cap);
		
	}
	return soh;
}
//读取SOC
u8 BQ_Get_Soc(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x2C, Recv, 2);
	if(err == 0)
	{
		if((Recv[4]<<8 | Recv[3]) <= 100)
			soc = (Recv[4]<<8 | Recv[3]);
		//printf("Capacity is :%d\r\n",cap);
		
	}
	return soc;
}


//读取剩余容量
u8 BQ_Get_retain_cap(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x0f, Recv, 2);
	if(err == 0)
	{
		if((Recv[4]<<8 | Recv[3]) <= 1800)
			retain_cap = (Recv[4]<<8 | Recv[3]);
		//printf("Capacity is :%d\r\n",cap);
		
	}
	return retain_cap;
}
//读取满充容量
u8 BQ_Get_full_cap(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x10, Recv, 2);
	if(err == 0)
	{
		if((Recv[4]<<8 | Recv[3]) <= 1800)
			full_cap = (Recv[4]<<8 | Recv[3]);
		//printf("Capacity is :%d\r\n",cap);
		
	}
	return full_cap;
}

//读取1-4节电芯的电压
u8 BQ_Get_Cell_1_4_Volt(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x71, Recv, 32);
	if(err == 0)
	{
		if((Recv[6]<<8 | Recv[5]) < 3650)
			Cell1Voltage = (Recv[6]<<8 | Recv[5]);
		
		if((Recv[8]<<8 | Recv[7]) < 3650)
			Cell2Voltage = (Recv[8]<<8 | Recv[7]);
		
		if((Recv[10]<<8 | Recv[9]) < 3650)
			Cell3Voltage = (Recv[10]<<8 | Recv[9]);
		
		if((Recv[12]<<8 | Recv[11]) < 3650)
			Cell4Voltage = (Recv[12]<<8 | Recv[11]);
		//printf("Cell volt is :%d\r\n",Cell1Voltage);	
		//printf("Cell volt is :%d\r\n",Cell2Voltage);	
	}
	return 0;
}

//读取5、6节电芯的电压
u8 BQ_Get_Cell_5_6_Volt(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x7b, Recv, 18);
	if(err == 0)
	{
		if((Recv[6]<<8 | Recv[5]) < 3650)
			Cell5Voltage = (Recv[6]<<8 | Recv[5]);
		if((Recv[12]<<8 | Recv[11]) < 3650)
			Cell6Voltage = (Recv[12]<<8 | Recv[11]);
	  //printf("Cell volt is :%d\r\n",Cell5Voltage);	
		//printf("Cell volt is :%d\r\n",Cell6Voltage);	
	}
	return 0;
}

//读取0x0072里面的TS1~TS4的温度，本次只是读取TS1的
u8 BQ_Get_TS1_Temp(void)
{
	int err=0;
	err = BQ40Z80_ReadData(0x72, Recv, 16);
	if(err == 0)
	{
			batt_temp = (Recv[8]<<8 | Recv[7]) - 2731.5 ;
		//printf("TS1 temp is :%d\r\n",Cell1Voltage);	

	}
	return 0;
}



