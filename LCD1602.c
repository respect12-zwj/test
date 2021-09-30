#include<lcd1602.h>

void delay1ms(uint c)   //��� 0us
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
  lcd_E=0;                                 //ʹ������
	lcd_RW=0;                                //д��
	lcd_RS=0;                                //��������
	
	datapins=com;                            //��������
	delay1ms(1);                             //�ȴ������ȶ�
	 
	lcd_E=1;                                 //д��ʱ��
	delay1ms(5);                             //����ʱ��
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
  lcdwriteCom(0x38);                       //����ʾ
  lcdwriteCom(0x0c);                       //���
  lcdwriteCom(0x06);                       //дһ��ָ���1
  lcdwriteCom(0x01);                       //����
  lcdwriteCom(0x80);	                     //����ָ�����
}