#include"counter.h"
#include"delay.h"
#include"lcd.h"
#include"remote control.h"
void counter()
{
 	unsigned char dat[4];
	unsigned char cuo[16]="   can't be 0   ";
	int num;

	int he,cha,ji,shang;
	double a1=0, a2=0, b1=0, b2=0, c1=0, c2=0,d1=0, d2=0, e1=0,e2=0;
	double i,one,two,three,four,five;				//第几位数
	extern  unsigned char IrValue[6]; 

	LcdInit();
//	LcdWriteCom(0x80);				   //（代替初始化）
//	for(i=0;i<80;i++)
//	{
//		LcdWriteData(' ');
//	}
	LcdWriteCom(0x06);
	LcdWriteCom(0x80);
kai: 	dat[0]=0,dat[1]=0,dat[2]=0,dat[3]=0,  			   //最开始输入的数
		i=0,a1=0, a2=0, b1=0, b2=0, c1=0, c2=0;	
		


		while(1)
		{
			switch(IrValue[2])
			{
				case 0x0c:
				if(i==0)a1= 1;if(i==1)a2=1;
				LcdWriteData('1');
				i++;delay(20);
				break;	 
				case 0x18:LcdWriteData('2');
				if(i==0)a1= 2;if(i==1)a2=2;i++;delay(20);
				break;
				case 0x5e:LcdWriteData('3');
				if(i==0)a1= 3;if(i==1)a2=3;i++;delay(20);
				break;
				case 0x09:LcdWriteData('+');
				delay(20);goto jia;						  //进到加法的程序
				break;
								  
				case 0x08:LcdWriteData('4');
				if(i==0)a1= 4;if(i==1)a2=4;i++;delay(20);
				break;
				case 0x1c:LcdWriteData('5');
				if(i==0)a1= 5;if(i==1)a2=5;i++;delay(20);
				break;
				case 0x5a:LcdWriteData('6');
				if(i==0)a1= 6;if(i==1)a2=6;i++;delay(20);
				break;
				case 0x15:LcdWriteData('-');				 //进到减法的程序
				i++;delay(20);goto jian;
				break;
	
				case 0x42:LcdWriteData('7');
				if(i==0)a1= 7;if(i==1)a2=7;i++;delay(20);
				break;
				case 0x52:LcdWriteData('8');
				if(i==0)a1= 8;if(i==1)a2=8;i++;delay(20);
				break;
				case 0x4a:LcdWriteData('9');
				if(i==0)a1= 9;if(i==1)a2=9;i++;delay(20);
				break;
				case 0x43:LcdWriteData('*');
				i++;delay(20);goto cheng;					 //乘法
				break;
	
				case 0x16:LcdWriteData('0');
				if(i==0)a1= 0;if(i==1)a2=0;i++;delay(20);
				break;
				case 0x07:	LcdInit();
				i++;delay(20);goto kai;
				break;
				case 0x44:LcdWriteData('=');
				i++;delay(20);
				break;
				case 0x40:	LcdWriteData('/');				  //除法
				delay(20);goto chu;    	
				break; 
			}      
			if(IrValue[2]==0x45)			   //返回选择界面
			{
				EA=0;
				ET0=0;
				return;
			}     			
			  if(i==1)									 //判断是一位数还是两位数
			  one=a1;
			  if(i==2)
			  one=a1*10+a2;	
			  while(1)
			  {
			   	 if(IRIN==0)
				 break;		
			  }
			 					 
	  }
jia:i=0;														 //加法运算
	while(1)
		{			
			switch(IrValue[2])
			{
				case 0x0c:LcdWriteData('1');
				if(i==0)b1= 1;if(i==1)  b2=1 ;
				i++;delay(20);
				break;	 
				case 0x18:LcdWriteData('2');
				if(i==0)b1= 2;if(i==1) b2=2 ;i++;delay(20);
				break;
				case 0x5e:LcdWriteData('3');
				if(i==0)b1= 3;if(i==1) b2=3 ;i++;delay(20);
				break;
				case 0x09:
				i++;delay(20);
				break;
								  
				case 0x08:LcdWriteData('4');
				if(i==0)b1= 4;if(i==1) b2=4 ;i++;delay(20);
				break;
				case 0x1c:LcdWriteData('5');
				if(i==0)b1= 5;if(i==1) b2=5 ;i++;delay(20);
				break;
				case 0x5a:LcdWriteData('6');
				if(i==0)b1= 6;if(i==1) b2=6 ;i++;delay(20);
				break;
				case 0x15:LcdWriteData('-');
				i++;delay(20);
				break;
	
				case 0x42:LcdWriteData('7');
				if(i==0)b1= 7;if(i==1) b2=7 ;i++;delay(20);
				break;
				case 0x52:LcdWriteData('8');
				if(i==0)b1= 8;if(i==1) b2=8 ;i++;delay(20);
				break;
				case 0x4a:LcdWriteData('9');
				if(i==0)b1= 9;if(i==1) b2=9 ;i++;delay(20);
				break;
				case 0x43:LcdWriteData('*');
				i++;delay(20);
				break;
	
				case 0x16:LcdWriteData('0');
				if(i==0)b1= 0;if(i==1) b2=0 ;i++;delay(20);
				break;
				case 0x07:	LcdInit();goto kai;
				i++;delay(20);
				break;
				case 0x44:LcdWriteData('=');
				i++;delay(20);goto he;
				break;
				case 0x40:	LcdWriteData('/');
				i++;delay(20);
				break;
			}    
			  if(i==1)
			  two=b1;
			  if(i==2)
			  two=b1*10+b2;	
			  while(1)
			  {
			   	 if(IRIN==0)
				 break;		
			  }		
	}	
he:	he=one+two;												   //计算两数之和
	dat[0]=he/100;
	dat[1]=he%100/10;
	dat[2]=he%10;
	if(dat[0]!=0)
	LcdWriteData('0'+dat[0]);
	if(dat[0]!=0||dat[1]!=0)
	LcdWriteData('0'+dat[1]);
	LcdWriteData('0'+dat[2]);					  
	delay(50);
    while(1)
  {
   	 if(IRIN==0)
	 {
	 	LcdInit();
		goto kai;
	 }	
  }
	

jian:i=0;
	 while(1)												  //减法运算
		{
			switch(IrValue[2])
			{
				case 0x0c:LcdWriteData('1');
				if(i==0)c1= 1;if(i==1)  c2=1 ;
				i++;delay(20);
				break;	 
				case 0x18:LcdWriteData('2');
				if(i==0)c1= 2;if(i==1) c2=2 ;i++;delay(20);
				break;
				case 0x5e:LcdWriteData('3');
				if(i==0)c1= 3;if(i==1) c2=3 ;i++;delay(20);
				break;
				case 0x09:LcdWriteData('+');
				i++;delay(20);
				break;
								  
				case 0x08:LcdWriteData('4');
				if(i==0)c1= 4;if(i==1) c2=4 ;i++;delay(20);
				break;
				case 0x1c:LcdWriteData('5');
				if(i==0)c1= 5;if(i==1) c2=5 ;i++;delay(20);
				break;
				case 0x5a:LcdWriteData('6');
				if(i==0)c1= 6;if(i==1) c2=6 ;i++;delay(20);
				break;
				case 0x15:
				i++;delay(20);
				break;
	
				case 0x42:LcdWriteData('7');
				if(i==0)c1= 7;if(i==1) c2=7 ;i++;delay(20);
				break;
				case 0x52:LcdWriteData('8');
				if(i==0)c1= 8;if(i==1) c2=8 ;i++;delay(20);
				break;
				case 0x4a:LcdWriteData('9');
				if(i==0)c1= 9;if(i==1) c2=9 ;i++;delay(20);
				break;
				case 0x43:LcdWriteData('*');
				i++;delay(20);
				break;
	
				case 0x16:LcdWriteData('0');
				if(i==0)c1= 0;if(i==1) c2=0 ;i++;delay(20);
				break;
				case 0x07:	LcdInit();goto kai;
				i++;delay(20);
				break;
				case 0x44:LcdWriteData('=');
				i++;delay(20);goto cha;
				break;
				case 0x40:	LcdWriteData('/');
				i++;delay(20);
				break;
			}
			   
			  if(i==1)
			  three=c1;
			  if(i==2)
			  three=c1*10+c2;	
			   while(1)
			  {
			   	 if(IRIN==0)
				 break;		
			  }		
		}						
cha:
		if(one>=three)											  //判断正负
		{
			cha=one-three;
			dat[0]=cha/10;
			dat[1]=cha%10;
			if(dat[0]!=0)
			LcdWriteData('0'+dat[0]);
			LcdWriteData('0'+dat[1]);				  
			delay(50);
		}
		else
			{
				cha=three-one;
				dat[0]=cha/10;
				dat[1]=cha%10;
				LcdWriteData('-');								  //加负号
				if(dat[0]!=0)
				LcdWriteData('0'+dat[0]);
				LcdWriteData('0'+dat[1]);				  
				delay(50);
			}
			 while(1)
			  {
			   	 if(IRIN==0)
				 {
				 	LcdInit();
					goto kai;
				}		
			  }		
		
cheng:i=0;													  //乘法运算
	 while(1)
		{
			switch(IrValue[2])
			{
				case 0x0c:LcdWriteData('1');
				if(i==0)d1= 1;if(i==1)  d2=1 ;
				i++;delay(20);
				break;	 
				case 0x18:LcdWriteData('2');
				if(i==0)d1= 2;if(i==1) d2=2 ;i++;delay(20);
				break;
				case 0x5e:LcdWriteData('3');
				if(i==0)d1= 3;if(i==1) d2=3 ;i++;delay(20);
				break;
				case 0x09:LcdWriteData('+');
				i++;delay(20);
				break;
								  
				case 0x08:LcdWriteData('4');
				if(i==0)d1= 4;if(i==1) d2=4 ;i++;delay(20);
				break;
				case 0x1c:LcdWriteData('5');
				if(i==0)d1= 5;if(i==1) d2=5 ;i++;delay(20);
				break;
				case 0x5a:LcdWriteData('6');
				if(i==0)d1= 6;if(i==1) d2=6 ;i++;delay(20);
				break;
				case 0x15:LcdWriteData('-');
				i++;delay(20);
				break;
	
				case 0x42:LcdWriteData('7');
				if(i==0)d1= 7;if(i==1) d2=7 ;i++;delay(20);
				break;
				case 0x52:LcdWriteData('8');
				if(i==0)d1= 8;if(i==1) d2=8 ;i++;delay(20);
				break;
				case 0x4a:LcdWriteData('9');
				if(i==0)d1= 9;if(i==1) d2=9 ;i++;delay(20);
				break;
				case 0x43:
				i++;delay(20);
				break;
	
				case 0x16:LcdWriteData('0');
				if(i==0)d1= 0;if(i==1) d2=0 ;i++;delay(20);
				break;
				case 0x07:	LcdInit();goto kai;
				i++;delay(20);
				break;
				case 0x44:LcdWriteData('=');
				i++;delay(20);goto ji;
				break;
				case 0x40:	LcdWriteData('/');
				i++;delay(20);
				break;
			}
	  
			  if(i==1)
			  four=d1;
			  if(i==2)
			  four=d1*10+d2;	
			   while(1)
			  {
			   	 if(IRIN==0)
				 break;		
			  }		
		}	
ji:	ji=one*four;										   //计算积
	dat[0]=ji/1000;
	dat[1]=ji%1000/100;
	dat[2]=ji%100/10;
	dat[3]=ji%10;
	if(dat[0]!=0)										   //判断万位是否为零是否显示
	LcdWriteData('0'+dat[0]);
	if(dat[0]!=0||dat[1]!=0)
	LcdWriteData('0'+dat[1]);
	if(dat[0]!=0&&dat[1]!=0||dat[2]!=0)
	LcdWriteData('0'+dat[2]);
	LcdWriteData('0'+dat[3]);					  
	delay(50);
		while(1)
			  {
			   	 if(IRIN==0)
				 {
				 	LcdInit();
					goto kai;
				}		
			  }		
chu: i=0;														   //除法运算
	 while(1)
		{
			switch(IrValue[2])
			{
				case 0x0c:LcdWriteData('1');
				if(i==0)e1= 1;if(i==1)e2=1 ;
				i++;delay(20);
				break;	 
				case 0x18:LcdWriteData('2');
				if(i==0)e1= 2;if(i==1) e2=2 ;i++;delay(20);
				break;
				case 0x5e:LcdWriteData('3');
				if(i==0)e1= 3;if(i==1) e2=3 ;i++;delay(20);
				break;
				case 0x09:LcdWriteData('+');
				i++;delay(20);
				break;
								  
				case 0x08:LcdWriteData('4');
				if(i==0)e1= 4;if(i==1) e2=4 ;i++;delay(20);
				break;
				case 0x1c:LcdWriteData('5');
				if(i==0)e1= 5;if(i==1) e2=5 ;i++;delay(20);
				break;
				case 0x5a:LcdWriteData('6');
				if(i==0)e1= 6;if(i==1) e2=6 ;i++;delay(20);
				break;
				case 0x15:LcdWriteData('-');
				i++;delay(20);
				break;
	
				case 0x42:LcdWriteData('7');
				if(i==0)e1= 7;if(i==1) e2=7 ;i++;delay(20);
				break;
				case 0x52:LcdWriteData('8');
				if(i==0)e1= 8;if(i==1) e2=8 ;i++;delay(20);
				break;
				case 0x4a:LcdWriteData('9');
				if(i==0)e1= 9;if(i==1) e2=9 ;i++;delay(20);
				break;
				case 0x43:LcdWriteData('*');
				i++;delay(20);
				break;
	
				case 0x16:LcdWriteData('0');
				if(i==0)
				{
					LcdWriteCom(0xc0);
					for(num=0;num<16;num++)
					LcdWriteData(cuo[num]);
					delay(200);
					LcdInit();
					goto kai;
				}
				if(i==1) e2=0 ;i++;delay(20);
				break;
				case 0x07:	LcdInit();goto kai;
				i++;delay(20);
				break;
				case 0x44:LcdWriteData('=');
				i++;delay(20);goto shang;
				break;
				case 0x40:
				i++;delay(20);
				break;
			}
		 
			  if(i==1)
			  five=e1;
			  if(i==2)
			  five=e1*10+e2;	
			   while(1)
			  {
			   	 if(IRIN==0)
				 break;		
			  }		
		}	
shang:	shang=one*100/five;					   //计算商（先扩大100倍）
		dat[0]=shang/1000;					   //万位
		dat[1]=shang%1000/100;
		dat[2]=shang%100/10;
		dat[3]=shang%10;
		if(dat[0]!=0)
		LcdWriteData('0'+dat[0]);
		LcdWriteData('0'+dat[1]);
		if(dat[3]!=0||dat[2]!=0)
		LcdWriteData('.');						   //小数点
		if(dat[3]!=0||dat[2]!=0)
		LcdWriteData('0'+dat[2]);
		if(dat[3]!=0)
		LcdWriteData('0'+dat[3]);					  
		delay(50);
		while(1)
			  {
			   	 if(IRIN==0)
				 {
				 	LcdInit();
					goto kai;
				}		
			  }											   
}