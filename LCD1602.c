#include<lcd1602.h>

void delay1ms(uint c)   //误差 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	} 	
}

void lcdwriteCom(uchar com)
{
  lcd_E=0;                                 //使能清零
	lcd_RW=0;                                //写入
	lcd_RS=0;                                //发送命令
	
	datapins=com;                            //放入数据
	delay1ms(1);                             //等待数据稳定
	 
	lcd_E=1;                                 //写入时序
	delay1ms(5);                             //保持时间
	lcd_E=0;
}

void lcdwriteData(uchar dat)
{
  lcd_E=0;
	lcd_RS=1;
	lcd_RW=0;
	
	datapins=dat;
	delay1ms(1);
	
	lcd_E=1;
	delay1ms(5);
	lcd_E=0;
}

void lcdInit()
{
  lcdwriteCom(0x38);                       //开显示
  lcdwriteCom(0x0c);                       //光标
  lcdwriteCom(0x06);                       //写一个指令加1
  lcdwriteCom(0x01);                       //清屏
  lcdwriteCom(0x80);	                     //设置指针起点
}