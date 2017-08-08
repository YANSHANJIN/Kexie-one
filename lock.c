#include"lock.h"
#include"lcd.h"
#include"delay.h"
#include"remote control.h"
/**************************************
函数名：lock
作用: 解锁
所用局部变量,数组：i,j  password[]
所用全局变量：
所用函数：LcdWriteCom	LcdWriteData
		  delay
***************************************/

void lock()
{
	unsigned char pass[]="Password correct";	  /************密码输入正确后显示****************/
	extern  unsigned char IrValue[6]; 		 /****IrValue[](全局数组)****/
	int i=0;				  	  /****局部i（用于密码）****/
	int j;						  /****局部j(显示数组)****/
	unsigned char password[]="Enter password:";
start:
	i=0;
	LcdInit();
	LcdWriteCom(0x80);
	for(j=0;j<15;j++)									//显示Enter password:
	{
		LcdWriteData(password[j]);	
	}
	delay(100);
	LcdWriteCom(0xc0);		
	while(1)
	{							
		switch(IrValue[2])
		{
		 	case 0x16:
				LcdWriteData('0');i=10;delay(50);break;

			case 0x0c:
				LcdWriteData('1');i=1;delay(50);break;
			case 0x18:
				LcdWriteData('2');i=10;delay(50);break;
			case 0x5e:
				LcdWriteData('3');i=10;delay(50);break;
			case 0x08:
				LcdWriteData('4');i=10;delay(50);break;

			case 0x1c:
				LcdWriteData('5');i=10;delay(50);break;
			case 0x5a:
				LcdWriteData('6');i=10;delay(50);break;
			case 0x42:
				LcdWriteData('7');i=10;delay(50);break;
			case 0x52:
				LcdWriteData('8');i=10;delay(50);break;

			case 0x4a:
				LcdWriteData('9');i=10;delay(50);break;
		}
		while(1)
		{
			if(IRIN==0)
			break;
		}    
		if(IrValue[2]==0x46)							//重输入密码
		goto start;    
		if(i==1)
		{
			break; 
		}
		if(i==10)
		{
		 	while(1)
			{						
				switch(IrValue[2])
				{
				 	case 0x16:
						LcdWriteData('0');delay(50);break;
		
					case 0x0c:
						LcdWriteData('1');delay(50);break;
					case 0x18:
						LcdWriteData('2');delay(50);break;
					case 0x5e:
						LcdWriteData('3');delay(50);break;
					case 0x08:
						LcdWriteData('4');delay(50);break;
		
					case 0x1c:
						LcdWriteData('5');delay(50);break;
					case 0x5a:
						LcdWriteData('6');delay(50);break;
					case 0x42:
						LcdWriteData('7');delay(50);break;
					case 0x52:
						LcdWriteData('8');delay(50);break;
		
					case 0x4a:
						LcdWriteData('9');delay(50);break;
				}
				while(1)
				{
					if(IRIN==0)
					break;
				}  
				if(IrValue[2]==0x46)							//重输入密码
				goto start;    				      	
			}
       }
	}

	while(1)
	{							
		switch(IrValue[2])
		{
		 	case 0x16:
				LcdWriteData('0');i=10;delay(50);break;

			case 0x0c:
				LcdWriteData('1');i=2;delay(50);break;
			case 0x18:
				LcdWriteData('2');i=10;delay(50);break;
			case 0x5e:
				LcdWriteData('3');i=10;delay(50);break;
			case 0x08:
				LcdWriteData('4');i=10;delay(50);break;

			case 0x1c:
				LcdWriteData('5');i=10;delay(50);break;
			case 0x5a:
				LcdWriteData('6');i=10;delay(50);break;
			case 0x42:
				LcdWriteData('7');i=10;delay(50);break;
			case 0x52:
				LcdWriteData('8');i=10;delay(50);break;

			case 0x4a:
				LcdWriteData('9');i=10;delay(50);break;
		}
		while(1)
		{
			if(IRIN==0)
			break;
		} 
		if(IrValue[2]==0x46)							//重输入密码
		goto start;           
		if(i==2)
		{
			break; 
		}
		if(i==10)
		{
		 	while(1)
			{						
				switch(IrValue[2])
				{
				 	case 0x16:
						LcdWriteData('0');delay(50);break;
		
					case 0x0c:
						LcdWriteData('1');delay(50);break;
					case 0x18:
						LcdWriteData('2');delay(50);break;
					case 0x5e:
						LcdWriteData('3');delay(50);break;
					case 0x08:
						LcdWriteData('4');delay(50);break;
		
					case 0x1c:
						LcdWriteData('5');delay(50);break;
					case 0x5a:
						LcdWriteData('6');delay(50);break;
					case 0x42:
						LcdWriteData('7');delay(50);break;
					case 0x52:
						LcdWriteData('8');delay(50);break;
		
					case 0x4a:
						LcdWriteData('9');delay(50);break;
				}
				while(1)
				{
					if(IRIN==0)
					break;
				}   
				if(IrValue[2]==0x46)							//重输入密码
				goto start;     			}
       }
	}
	
	while(1)
	{							
		switch(IrValue[2])
		{
		 	case 0x16:
				LcdWriteData('0');i=10;delay(50);break;

			case 0x0c:
				LcdWriteData('1');i=10;delay(50);break;
			case 0x18:
				LcdWriteData('2');i=10;delay(50);break;
			case 0x5e:
				LcdWriteData('3');i=10;delay(50);break;
			case 0x08:
				LcdWriteData('4');i=10;delay(50);break;

			case 0x1c:
				LcdWriteData('5');i=3;delay(50);break;
			case 0x5a:
				LcdWriteData('6');i=10;delay(50);break;
			case 0x42:
				LcdWriteData('7');i=10;delay(50);break;
			case 0x52:
				LcdWriteData('8');i=10;delay(50);break;

			case 0x4a:
				LcdWriteData('9');i=10;delay(50);break;
		}
		while(1)
		{
			if(IRIN==0)
			break;
		}     
		if(IrValue[2]==0x46)							//重输入密码
		goto start;     		   
		if(i==3)
		{
			break; 
		}
		if(i==10)
		{
		 	while(1)
			{						
				switch(IrValue[2])
				{
				 	case 0x16:
						LcdWriteData('0');delay(50);break;
		
					case 0x0c:
						LcdWriteData('1');delay(50);break;
					case 0x18:
						LcdWriteData('2');delay(50);break;
					case 0x5e:
						LcdWriteData('3');delay(50);break;
					case 0x08:
						LcdWriteData('4');delay(50);break;
		
					case 0x1c:
						LcdWriteData('5');delay(50);break;
					case 0x5a:
						LcdWriteData('6');delay(50);break;
					case 0x42:
						LcdWriteData('7');delay(50);break;
					case 0x52:
						LcdWriteData('8');delay(50);break;
		
					case 0x4a:
						LcdWriteData('9');delay(50);break;
				}	
				while(1)
				{
					if(IRIN==0)
					break;
				}    
				if(IrValue[2]==0x46)							//重输入密码
				goto start;     			 
			}
       }
	}

	while(1)
	{							
		switch(IrValue[2])
		{
		 	case 0x16:
				LcdWriteData('0');i=10;delay(50);break;

			case 0x0c:
				LcdWriteData('1');i=10;delay(50);break;
			case 0x18:
				LcdWriteData('2');i=10;delay(50);break;
			case 0x5e:
				LcdWriteData('3');i=10;delay(50);break;
			case 0x08:
				LcdWriteData('4');i=10;delay(50);break;

			case 0x1c:
				LcdWriteData('5');i=10;delay(50);break;
			case 0x5a:
				LcdWriteData('6');i=4;delay(50);break;
			case 0x42:
				LcdWriteData('7');i=10;delay(50);break;
			case 0x52:
				LcdWriteData('8');i=10;delay(50);break;

			case 0x4a:
				LcdWriteData('9');i=10;delay(50);break;
		}
		
		if(i==4)
		{
			break; 
		}
		if(i==10)
		{
		 	while(1)
			{						
				switch(IrValue[2])
				{
				 	case 0x16:
						LcdWriteData('0');delay(50);break;
		
					case 0x0c:
						LcdWriteData('1');delay(50);break;
					case 0x18:
						LcdWriteData('2');delay(50);break;
					case 0x5e:
						LcdWriteData('3');delay(50);break;
					case 0x08:
						LcdWriteData('4');delay(50);break;
		
					case 0x1c:
						LcdWriteData('5');delay(50);break;
					case 0x5a:
						LcdWriteData('6');delay(50);break;
					case 0x42:
						LcdWriteData('7');delay(50);break;
					case 0x52:
						LcdWriteData('8');delay(50);break;
		
					case 0x4a:
						LcdWriteData('9');delay(50);break;
				}	
				while(1)
				{
					if(IRIN==0)
					break;
				}        
	  			if(IrValue[2]==0x46)							//重输入密码
				goto start;    
			}
       }
	}
	LcdInit();	
	LcdWriteCom(0x80);		
	for(j=0;j<16;j++)			
	{			 								//显示pass correct
		LcdWriteData(pass[j]);
	}
	delay(200);
}
