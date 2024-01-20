#include "stc8g.h"
#include "intrins.h"

unsigned char Light_Flag;
unsigned char Rdat = 0xFF, Gdat = 0x00, Bdat = 0x00;
unsigned char Rec_Cnt;

void Delay300us(void)	//@24.000MHz
{
	unsigned char data i, j;

	i = 10;
	j = 87;
	do
	{
		while (--j);
	} while (--i);
}

void Delay2000ms(void)	//@24.000MHz
{
	unsigned char data i, j, k;

	i = 244;
	j = 130;
	k = 4;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void WS2812_Send_Bit(bit data_bit)
{
	if(data_bit)
	{
		P33 = 1;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		P33 = 0;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	}
	else
	{
		P33 = 1;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		P33 = 0;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	}
}

void WS2812_Rand_Color(unsigned char r,unsigned char g,unsigned char b)
{
	WS2812_Send_Bit(g&0x80);WS2812_Send_Bit(g&0x40);WS2812_Send_Bit(g&0x20);WS2812_Send_Bit(g&0x10);
	WS2812_Send_Bit(g&0x08);WS2812_Send_Bit(g&0x04);WS2812_Send_Bit(g&0x02);WS2812_Send_Bit(g&0x01);
	
	WS2812_Send_Bit(r&0x80);WS2812_Send_Bit(r&0x40);WS2812_Send_Bit(r&0x20);WS2812_Send_Bit(r&0x10);
	WS2812_Send_Bit(r&0x08);WS2812_Send_Bit(r&0x04);WS2812_Send_Bit(r&0x02);WS2812_Send_Bit(r&0x01);
	
	WS2812_Send_Bit(b&0x80);WS2812_Send_Bit(b&0x40);WS2812_Send_Bit(b&0x20);WS2812_Send_Bit(b&0x10);
	WS2812_Send_Bit(b&0x08);WS2812_Send_Bit(b&0x04);WS2812_Send_Bit(b&0x02);WS2812_Send_Bit(b&0x01);
}

void Uart1_Init(void)	//9600bps@24.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x8F;			//设置定时初始值
	TH1 = 0xFD;			//设置定时初始值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES = 1;				//使能串口1中断
}

void main()
{
	unsigned char i;
	
	P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0x00;
    P2M0 = 0x00;
    P2M1 = 0x00;
    P3M0 = 0x00;
    P3M1 = 0x00;
    P4M0 = 0x00;
    P4M1 = 0x00;
    P5M0 = 0x00;
    P5M1 = 0x00;
	
	P55 = 1;
	P33 = 0;
	
    IT0 = 1;
    EX0 = 1;
	
	Uart1_Init();
	
	EA = 1;
	
	PCON = 0x02;
	_nop_();

	while (1)
	{
		if (P32 == 0)
		{
			Delay2000ms();
			if (P32 == 0)
			{
				Light_Flag = ~Light_Flag;
			}
		}
		
		if (Light_Flag)
		{
			P55 = 0;
			for(i = 0; i < 12; i++)
			{
				WS2812_Rand_Color(Rdat, Gdat, Bdat);
			}
			P33 = 0;
			Delay300us();
		}
		else
		{
			P55 = 1;
			PCON = 0x02;
			_nop_();
		}
	}
}

void INT0_Isr() interrupt 0 
{

}

void Uart1_Isr(void) interrupt 4
{
	if (RI)				//检测串口1接收中断
	{
		RI = 0;			//清除串口1接收中断请求位
		switch (Rec_Cnt)
		{
			case 0:
				Rdat = SBUF;
				Rec_Cnt++;
				break;
			case 1:
				Gdat = SBUF;
				Rec_Cnt++;
				break;
			case 2:
				Bdat = SBUF;
				Rec_Cnt++;
				break;
			default:
				Rec_Cnt = 0;
				break;
		}
		
	}
}