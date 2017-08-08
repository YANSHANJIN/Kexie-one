#include<reg51.h>
#include"lcd.h"
#include"lock.h"
#include"remote control.h"
#include"delay.h"
#include"jean.h"
#include"counter.h"

unsigned char menu[]="Select options: ";
unsigned char options[]="jean music counter";
unsigned char option1[]="jean";
unsigned char option2[]="music";
unsigned char option3[]="counter";

unsigned  int C;     //���涨ʱ���Ķ�ʱ����  
unsigned char IrValue[6];				  /****IrValue[6]����****/


void main()
{
	unsigned int i;					  /*******������ʾ����*******/
	IrInit();	
	IrValue[2]=0;
	lock();							   //����
start:
	IrInit();							//ң�س�ʼ��
	LcdInit();						   //lcd��ʼ��
/***********************
	ѡ�����
***********************/		

	LcdWriteCom(0x80);
	for(i=0;i<16;i++)									//��ʾĿ¼ѡ��
	{
		LcdWriteData(menu[i]);	
	}
	LcdWriteCom(0xc0+9);
	for(i=0;i<18;i++)
	{
		LcdWriteData(options[i]);
	}  
	LcdWriteCom(0x07);
	while(1)
	{
		LcdWriteCom(0xc0+9);
	 	for(i=0;i<18;i++)
		{
			LcdWriteData(options[i]);
			delay(50);
			if((IrValue[2]==0x45)||(IrValue[2]==0x46)||(IrValue[2]==0x47))
			goto select;
		}  
	}
select:
	while(1)
	{
		switch(IrValue[2])
		{
			case 0x45:
				LcdInit();											 //��ʾѡ����Ļ
				LcdWriteCom(0xc0+4);
				for(i=0;i<4;i++)
				{
					LcdWriteData(option1[i]);
				}  
				delay(5);
				goto tt1;
				break;
			case 0x46:
				LcdInit();
				LcdWriteCom(0xc+4); 
				for(i=0;i<5;i++)
				{
					LcdWriteData(option2[i]);
				}  		 
				delay(5);
				goto tt2;
				break;
			case 0x47:
				LcdInit();
				LcdWriteCom(0xc0+4);  								  	 //��ʾѡ��3
				for(i=0;i<6;i++)
				{
					LcdWriteData(option3[i]);
				} 
				delay(5);
				goto tt3;
				break;
		}
		while(1)
		{
			if(IRIN==0)
			break;
		}
	}
	LcdInit();		
/***************************
	ѡ��������
***************************/
tt1: electronic_organ(); 
	goto start;
tt2: music();
	goto start;
tt3: counter();
	goto start;
}

