#include"jean.h"
#include"delay.h"
#include"lcd.h"
#include"remote control.h"
void electronic_organ()
{
	int i;
	unsigned  int code f[]={dao,re,mi,fa,sao,la,xi}; 
	extern unsigned char IrValue[6];
	extern unsigned  int C;     //储存定时器的定时常数(全局变量)          	

	IrInit();
	EA=1;         //开总中断 
	ET0=1;        //定时器T0中断允许 
	TMOD=0x00;    // 使用定时器T0的模式1（13位计数器） 
  
	while(1)       //无限循环 
	{
		 
		switch (IrValue[2])
			{
				case(0x0c) :	
			    		i=0;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('d');
						LcdWriteData('a');
						LcdWriteData('o');
						break;
				case(0x18) :	
				   		i=1;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('r');
						LcdWriteData('e');
						break;
				case(0x5e):	
			       		i=2;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('m');
						LcdWriteData('i');
						break;
				case(0x08) :	
						i=3;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('f');
						LcdWriteData('a');
						break;					 
		     	case(0x1c) :	
	               		i=4;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('s');
						LcdWriteData('a');
						LcdWriteData('o');
						break;
				case(0x5a) :	
			      		i=5;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('l');
						LcdWriteData('a');
						break;
				case(0x42) :
				   		i=6;
						LcdInit();
						LcdWriteCom(0x80+6);	
						LcdWriteData('x');
						LcdWriteData('i');
						break;
				default:
						i=8;break;
			}
			if(IrValue[2]==0x45)
			{
				EA=0;
				ET0=0;
				return;
			}
			
				
			if(i==8)
			continue;
			C=460830/f[i];        
			TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
			TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
			TR0=1;             //启动定时器T0
			delay1();          //延时1个节拍单位 
			TR0=0;                     //关闭定时器T0 
			IrValue[2]=0; 		                                                          
	}               
}

void music()
{
	unsigned char i,j,z; 
//丑八怪
	unsigned char name1[4]="ugly";
	unsigned  int code f1[]={dao,re,mi,re,mi,re,mi,sao,mi,mi,re,sao,mi,mi,dao,re,re,re,re,dao,re,re,re,
						l_la,l_la,l_xi,dao,l_xi,dao,l_xi,dao,sao,re,re,dao,l_xi,l_xi,l_la,l_la,l_sao,
						l_la,l_sao,l_la,dao,mi,mi,
						dao,re,mi,re,mi,re,mi,sao,mi,mi,re,sao,mi,mi,dao,re,re,re,re,dao,re,re,re,
						l_la,l_la,l_xi,dao,l_xi,dao,l_xi,dao,sao,re,re,dao,l_xi,l_la,0xff};
	unsigned int G1[]={1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,2,2,2,1,1,4,
				    	1,1,1,1,1,1,1,1,1,2,1,1,1,3,1,1,1,1,1,2,1,4,
						2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,2,2,1,1,4,
						1,1,1,1,1,1,1,1,1,2,4,4,2,5};

//生日快乐
	unsigned char name2[14]="happy birthday";
   	unsigned  int code f2[]={sao,sao,la,sao,h_dao,xi,sao,sao,la,sao,h_re,h_dao,sao,sao,h_sao,h_mi,h_dao,xi,la,la,la,	
							h_sao,h_sao,h_mi,h_dao,h_re,h_dao,0xff};

	unsigned int G2[]={1,1,2,2,2,2,4,  1,1,2,2,2,2,2,
					  1,1,2,2,2,2,2,4,  1,1,2,2,2,4,2}; 

//两只老虎 
	unsigned char name3[10]="two tigers";
	unsigned  int code f3[]={dao,re,mi,dao, dao,re,mi,dao,
							 mi,fa,sao, mi,fa,sao, 	sao,la,
							 sao,fa,mi,dao,sao,la,sao,fa,mi,
							 dao,re,l_sao,dao,0xff};                            
  	unsigned int G3[]={2,2,2,2,2,2,2,2, 2,2,4,2,2,4, 
					   1,1,1,1,2,2, 1,1,1,1,2,2, 2,2,4,2,2,4};
//猪八戒
	unsigned char name4[14]="pig eight quit";
	unsigned  int code f4[]={re,la,h_dao,la,re,fa,re,fa,re,fa,la,la,sao,la,fa,re,la,h_dao,h_re,h_re,h_re,la,h_dao,
	                         la,h_dao,la,h_dao,h_re,h_re,h_re,la,h_dao,h_dao,re,h_dao,re,la,sao,la,fa,sao,sao,sao,						 
							 fa,sao,la,h_dao,h_re,h_la,la,h_la,la,h_la,la,h_la,la,h_la,la,sao,la,fa,sao,sao,sao,fa,sao,la,						 
							 h_dao,h_re,h_re,0xff} ;
	unsigned int G4[]={4,3,1,2,2,4,1,1,1,1,4,1,1,1,1,4,3,1,2,
					   2,2,2,4,1,1,1,1,2,2,2,2,4,2,2,2,2,2,2,
					   2,4,4,4,2,1,1,2,2,4,4,4,4,2,2,2,2,2,2,
					   2,4,4,4,2,1,1,2,2,4,4};					
	extern unsigned char IrValue[6];
	extern unsigned  int C;     //储存定时器的定时常数(全局变量) 


start:
	IrInit();							//遥控初始化
	LcdInit();	
	while(1)
	{
		switch(IrValue[2])										//选择歌曲
			{
				case 0x0c:
					LcdInit();
					LcdWriteCom(0x80+6);
					for(z=0;z<4;z++)
					LcdWriteData(name1[z]);
					goto m1;
					break;
				case 0x18:
					LcdInit();
					LcdWriteCom(0x80+1);
					for(z=0;z<14;z++)
					{
						LcdWriteData(name2[z]);
					}
					goto m2;
					break;
				case 0x5e:
					LcdInit();
					LcdWriteCom(0x80+3);
					for(z=0;z<10;z++)
					LcdWriteData(name3[z]);
					goto m3;
					break;
				case 0x08:
					LcdInit();
					LcdWriteCom(0x80+1);
					for(z=0;z<14;z++)
					LcdWriteData(name4[z]);
					goto m4;
					break;
	 		  }
			  
			if(IrValue[2]==0x45)			   //返回选择界面
			{
				EA=0;
				ET0=0;
				return;
			}   
	}
m1:
	EA=1;         //开总中断 
	ET0=1;        //定时器T0中断允许 
	TMOD=0x00;    // 使用定时器T0的模式1（13位计数器）
	while(1)       //无限循环 
			{
				i=0;   //从第1个音符f[0]开始播放 
				while(f1[i]!=0xff)            //只要没有读到结束标志就继续播放 
				{
					C=460830/f1[i];        
					TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
					TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
					TR0=1;             //启动定时器T0
					for(j=0;j<G1[i];j++)  //控制节拍数 
					delay2();          //延时1个节拍单位 
					TR0=0;                     //关闭定时器T0
					i++;                 //播放下一个音符 												
					if(IrValue[2]==0x45)			   //返回选择界面
					{
						EA=0;
						ET0=0;
						return;
					}   
					if(IrValue[2]==0x43)			   //返回选择界面
					{
						EA=0;         //开总中断 
						ET0=0;   
						goto start;
					}         	      
				}                                                  
			}                    
m2:
	EA=1;         //开总中断 
	ET0=1;        //定时器T0中断允许 
	TMOD=0x00;    // 使用定时器T0的模式1（13位计数器）
	while(1)       //无限循环 
			{
				i=0;   //从第1个音符f[0]开始播放 
				while(f2[i]!=0xff)            //只要没有读到结束标志就继续播放 
				{
					C=460830/f2[i];        
					TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
					TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
					TR0=1;             //启动定时器T0
					for(j=0;j<G2[i];j++)  //控制节拍数 
					delay2();          //延时1个节拍单位 
					TR0=0;                     //关闭定时器T0
					i++;                 //播放下一个音符 
					
					if(IrValue[2]==0x45)			   //返回选择界面
					{
						EA=0;
						ET0=0;
						return;
					}  
					if(IrValue[2]==0x43)			   //返回选择界面
					{
						EA=0;         //开总中断 
						ET0=0;   
						goto start;
					}          
				}                                                 
			}    
			
m3:
	EA=1;         //开总中断 
	ET0=1;        //定时器T0中断允许 
	TMOD=0x00;    // 使用定时器T0的模式1（13位计数器）
	while(1)       //无限循环 
			{
				i=0;   //从第1个音符f[0]开始播放 
				while(f3[i]!=0xff)            //只要没有读到结束标志就继续播放 
				{
					C=460830/f3[i];        
					TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
					TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
					TR0=1;             //启动定时器T0
					for(j=0;j<G3[i];j++)  //控制节拍数 
					delay2();          //延时1个节拍单位 
					TR0=0;                     //关闭定时器T0
					i++;                 //播放下一个音符 
					
					if(IrValue[2]==0x45)			   //返回选择界面
					{
						EA=0;
						ET0=0;
						return;
					}    
					if(IrValue[2]==0x43)			   //返回选择界面
					{
						EA=0;         //开总中断 
						ET0=0;   
						goto start;
					}    
				}                                                 
			}  
			
m4:
	EA=1;         //开总中断 
	ET0=1;        //定时器T0中断允许 
	TMOD=0x00;    // 使用定时器T0的模式1（13位计数器）
	while(1)       //无限循环 
			{
				i=0;   //从第1个音符f[0]开始播放 
				while(f4[i]!=0xff)            //只要没有读到结束标志就继续播放 
				{
					C=460830/f4[i];        
					TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
					TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
					TR0=1;             //启动定时器T0
					for(j=0;j<G4[i];j++)  //控制节拍数 
					delay2();          //延时1个节拍单位 
					TR0=0;                     //关闭定时器T0
					i++;                 //播放下一个音符 
					
					if(IrValue[2]==0x45)			   //返回选择界面
					{
						EA=0;
						ET0=0;
						return;
					}
					if(IrValue[2]==0x43)			   //返回选择界面
					{
						EA=0;         //开总中断 
						ET0=0;   
						goto start;
					}              
				}                                                 			                 	    
			}
}
/***********************************************************
函数功能：定时器T0的中断服务子程序，使P3.7引脚输出音频的方波 
************************************************************/
void Time0() interrupt 1 
{
	extern unsigned  int C;    
	sound=!sound;      //将P3.7引脚输出电平取反，形成方波  
	TH0=(8192-C)/32;   //可证明这是13位计数器TH0高8位的赋初值方法 
	TL0=(8192-C)%32;   //可证明这是13位计数器TL0低5位的赋初值方法 
}
