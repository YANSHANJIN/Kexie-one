#ifndef __REMOTE_CONTROL_H_
#define __REMOTE_CONTROL_H_
#include<reg51.h>
void DelayMs(unsigned int x);
void IrInit();							  /****IrInit*********����****/
sbit IRIN=P3^2;
#endif