
#ifndef _MYRTTINPUT_H
#define _MYRTTINPUT_H

#include "rtthread.h"





void iic_thread_entry(void* parameter);
void oled_thread_entry(void* parameter);
void can_slave_entry(void* parameter);

#endif

