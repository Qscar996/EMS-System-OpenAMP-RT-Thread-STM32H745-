#ifndef __BQ40Z80_H
#define __BQ40Z80_H 


#include "myiic.h"





extern uint16_t voltage;
extern uint16_t temp;
extern uint16_t cap;
extern uint16_t soc;
extern uint16_t soh;
extern uint16_t retain_cap	;
extern uint16_t full_cap;		
extern int16_t current;
extern uint16_t Cell1Voltage;
extern uint16_t Cell2Voltage;
extern uint16_t Cell3Voltage;
extern uint16_t Cell4Voltage;
extern uint16_t Cell5Voltage;
extern uint16_t Cell6Voltage;
extern uint16_t batt_temp;


extern int32_t clc_soc;
extern int32_t clc_soh;



#define BQ40Z80_ADDR 0x16	// …Ë±∏I2Cµÿ÷∑

u8 BQ40Z80_ReadData(uint8_t reg_addr, uint8_t* data, uint8_t len);


u8 BQ_Get_Temp(void);
u8 BQ_Get_Volt(void);
int BQ_Get_Current(void);
u8 BQ_Get_Capacity(void);
u8 BQ_Get_Soh(void);
u8 BQ_Get_Soc(void);
u8 BQ_Get_Cell_1_4_Volt(void);
u8 BQ_Get_Cell_5_6_Volt(void);
u8 BQ_Get_TS1_Temp(void);
u8 BQ_Get_full_cap(void);
u8 BQ_Get_retain_cap(void);


#endif


