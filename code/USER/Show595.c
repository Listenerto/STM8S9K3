#include "Show595.h"
#include <string.h>
#include <stdio.h>
 u8 t;
 bool hapen_flag=0;
const u8 ghc595_buf[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const u8 ghc595_buf1[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

const u8 smile[96]={0x00,0x00,0x00,0x00,0x3C,0x00,0x80,0xFF,0x01,0xC0,0xE7,0x03,0xE0,0x00,0x07,0x70,0x00,
0x0E,0x38,0x00,0x1C,0x18,0x00,0x18,0x0C,0x40,0x30,0x0C,0xC0,0x30,0x86,0xC1,0x21,0x86,0x83,0x61,0x86,0x01,
0x63,0x02,0x00,0x63,0x02,0x00,0x42,0x02,0x00,0x42,0x02,0x00,0x42,0x02,0x00,0x42,0x02,0x00,0x43,0x86,0x01,
0x63,0x86,0x83,0x63,0x86,0x81,0x61,0x0C,0xC0,0x30,0x0C,0x40,0x30,0x1C,0x00,0x10,0x18,0x00,0x00,0x30,0x00,
0x00,0x70,0x00,0x00,0xE0,0xC1,0x01,0x80,0xFF,0x01,0x00,0x7E,0x00,0x00,0x00,0x00};
/* (32X 24 ) */
const u8 Lightning[96]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,
0x00,0x00,0x3C,0x00,0x00,0x3F,0x00,0xC0,0x3F,0x00,0xF0,0x33,0x70,0xF8,0x30,0x7E,0x7C,0xB0,0x7F,0x1E,0xF0,0x3F,0x0E,0xF0,0x1F,0x0E,0x70,
0x0E,0x0E,0x00,0x0F,0x0E,0x00,0x07,0x0E,0x83,0x03,0xCE,0xC7,0x01,0xEE,0xE7,0x01,0xFE,0xE7,0x00,0x7E,0x77,0x00,0x1E,0x3F,0x00,0x0C,0x3F,0x00,0x00,0x1F,
0x00,0x00,0x0F,0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/*"C:\Users\MD\Desktop\����.png-2023-07-03-13-13-05-477.bmp",0*/
/* (32 X 24 ) */
const u8 Love[96]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x80,0x3F,0x00,0xE0,0xFF,0x00,0xE0,0xFF,0x01,0xF0,0xFF,0x03,
0xF8,0xFF,0x07,0xF8,0xFF,0x07,0xF8,0xFF,0x0F,0xF8,0xFF,0x1F,0xF8,0xFF,0x1F,0xF8,0xFF,0x3F,0xF8,0xFF,0x7F,0xF8,0xFF,0x7F,0xF0,
0xFF,0xFF,0xF0,0xFF,0xFF,0xF0,0xFF,0xFF,0xF8,0xFF,0x7F,0xF8,0xFF,0x7F,0xF8,0xFF,0x3F,0xF8,0xFF,0x1F,0xF8,0xFF,0x1F,0xF8,0xFF,0x0F,
0xF8,0xFF,0x07,0xF8,0xFF,0x07,0xF0,0xFF,0x03,0xE0,0xFF,0x01,0xE0,0xFF,0x00,0x80,0x3F,0x00,0x00,0x0E,0x00,0x00,0x00,0x00};
/*"C:\Users\MD\Desktop\����.png-2023-07-03-13-13-05-454.bmp",0*/
/* (32 X 24 ) */
const u8 Like[96]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x3F,0x00,0xFC,0x7F,0x00,0xFC,0x7F,0x00,0x0C,0x60,0x00,0xFC,0x7F,
0x00,0xFC,0x7F,0x00,0xFC,0x7F,0x00,0x0E,0x60,0x00,0x0E,0x60,0x00,0x07,0x60,0xF8,0x07,0x60,0xFC,0x03,0x60,0xFC,0x00,
0x60,0x0C,0x00,0x60,0x0C,0x00,0x60,0xDC,0x03,0x60,0xFC,0x03,0x60,0xF8,0x03,0x60,0x00,0x03,0x60,0x00,0x03,0x60,0x00,
0x03,0x60,0x00,0x03,0x60,0x00,0x03,0x60,0x00,0x03,0x60,0x00,0x03,0x70,0x00,0x03,0x7F,0x00,0xE3,0x3F,0x00,0xFF,0x0F,0x00,0xFE,0x00,0x00,0x0C,0x00};
/*"C:\Users\MD\Desktop\����.png-2023-07-03-13-13-05-429.bmp",0*/
/* (32 X 24 ) */
const u8 my_name[216]={0x00,0x80,0x40,0x20,0x80,0x60,0x60,0x84,0x61,0xE4,0xB4,0x30,0xCC,0xFE,0x30,0x1C,0xFF,0x18,0xDC,0xC7,0x18,
0xE8,0xE1,0x0C,0x68,0xB3,0x0E,0xC8,0xBB,0x07,0xC8,0xFD,0x7F,0x08,0xFF,0x7F,0xF8,0xE7,0x7F,0xF8,0xAB,0x03,0xF8,0x98,0x06,0x08,0xB8,
0x0E,0x08,0xBE,0x1C,0xF8,0x9F,0x18,0xFC,0x8F,0x38,0xFC,0x81,0x38,0x80,0xC7,0x30,0x00,0xC7,0x30,0x00,0x86,0x10,0x00,0x00,0x10,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x01,0xF0,0xFF,0x01,0x10,0x42,0x00,0x10,0x42,0x00,0x10,0x42,0x40,0x10,0x42,
0x20,0xF0,0xFF,0x10,0x00,0x00,0x08,0x00,0x00,0x04,0x00,0xC0,0x03,0xFC,0xFF,0x00,0x04,0x21,0x00,0x04,0x21,0x10,0x04,0x21,0x10,0x04,
0x21,0x20,0x04,0x21,0x60,0xFC,0xFF,0x3F,0xFC,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x02,0x10,0x00,0x02,0x18,0x04,0x02,0x08,0x0C,0x02,0x04,0x18,0xFF,0x07,0x00,0x02,0x08,0x20,0x00,0x10,0x20,
0x00,0x10,0x20,0x00,0x20,0x22,0xFF,0x27,0x24,0x49,0x22,0x38,0x49,0x62,0xA0,0x49,0x62,0x60,0x49,0x42,0x20,0x49,0x42,0x30,0x49,0x42,
0x2C,0x49,0x42,0x24,0xFF,0x47,0x20,0xFF,0x67,0x20,0x00,0x60,0x20,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x00
};

const u8 Six[36]={0x00,0xF8,0x00,0x00,0xFF,0x07,0x80,0xFF,0x0F,0xC0,0xFF,0x1F,0xE0,0x18,0x1C,0x60,0x18,0x18,0x20,0x08,0x10,
0xE0,0x18,0x18,0xE0,0xF9,0x1F,0xE0,0xF9,0x0F,0xC0,0xF0,0x07,0x00,0x00,0x00};/*"6",0*/
/* (12 X 24 , ���� ) */




/*"��",0*/
/* (24 X 24 , ���� ) */

/*"��",1*/
/* (24 X 24 , ���� ) */

/*"��",2*/
/* (24 X 24 , ���� ) */
/*******************************************************************************
* �� �� ��       : 74HC595_INIT(void)
* ��������		��ʼ��74HC595����
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void INIT_74HC595(void)
{
  GPIO_Init(GPIOC, (GPIO_Pin_TypeDef)(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4), GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_WriteHigh(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4));
  hc595_write_data(0xFF);

}

/*******************************************************************************
* �� �� ��       : delay_10us
* ��������		 : ��ʱ������ten_us=1ʱ����Լ��ʱ10us
* ��    ��       : ten_us
* ��    ��    	 : ��
*******************************************************************************/
void delay_10us(u16 ten_us)
{
  
        ten_us;
	while(ten_us--);
	
}

/*******************************************************************************
* �� �� ��       : delay_ms
* ��������		 : ms��ʱ������ms=1ʱ����Լ��ʱ1ms
* ��    ��       : ten_us
* ��    ��    	 : ��
*******************************************************************************/
void delay_ms(u16 ms)
{
	u16 i,j;
	for(i=ms;i>0;i--)
		for(j=110;j>0;j--);
}
/*******************************************************************************
* �� �� ��         : hc595_write_data(u8 dat)
* ��������		   : ��74HC595д��һ���ֽڵ�����
* ��    ��         : dat������
* ��    ��         : ��
*******************************************************************************/
void hc595_write_data(u8 dat)
{
	u8 i=0;
	
	for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat>>7)//���ȴ���һ���ֽ��еĸ�λ
                  GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                   
                  GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
		dat<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	GPIO_WriteLow(GPIOC,GPIO_PIN_3);
	delay_10us(1);
	GPIO_WriteHigh(GPIOC,GPIO_PIN_3);//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������	
}
/*******************************************************************************
* �� �� ��         : Show_bmp(u8 *dat,u8 wigth)
* ��������		   : ������HC595д��һ����Ϊ24������
* ��    ��         : dat1��dat2��dat3�����������ÿ�˸�Ϊһ�飨���룩 (˳������ʽ)
* ��    ��         : ��
*******************************************************************************/
void show_24high(u8 dat1,u8 dat2,u8 dat3)
{

        u8 i=0;
	
	for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat1&0x01)//���ȴ���һ���ֽ��еĸ�λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                    
                  GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
		dat1>>=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat2&0x01)//���ȴ���һ���ֽ��еĸ�λ
                 GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                    GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
                 
		dat2>>=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat3&0x01)//���ȴ���һ���ֽ��еĸ�λ
                 GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                   GPIO_WriteHigh(GPIOC,GPIO_PIN_4);

		dat3>>=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	GPIO_WriteLow(GPIOC,GPIO_PIN_3);
	delay_10us(1);
	GPIO_WriteHigh(GPIOC,GPIO_PIN_3);//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������


}

void show_24high_L(u8 dat1,u8 dat2,u8 dat3)
{

        u8 i=0;
	
	for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat3>>7)//���ȴ���һ���ֽ��еĸ�λ
                GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
                  else 
                   GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                 
		dat3<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat2>>7)//���ȴ���һ���ֽ��еĸ�λ
                  GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
                  else 
                    
                 GPIO_WriteLow(GPIOC,GPIO_PIN_4);
		dat2<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat1>>7)//���ȴ���һ���ֽ��еĸ�λ
                  GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
                  else 
                  
                    GPIO_WriteLow(GPIOC,GPIO_PIN_4);
		dat1<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	GPIO_WriteLow(GPIOC,GPIO_PIN_3);
	delay_10us(1);
	GPIO_WriteHigh(GPIOC,GPIO_PIN_3);//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������


}

/*******************************************************************************
* �� �� ��         : Show_bmp(u8 *dat,u8 wigth)
* ��������		   : д��һ����Ϊ24����������ʾ������
* ��    ��         : *dat������ȡģ�����룩��wigth������ȡģ�Ŀ�ȣ���Ϊָ�뺯�����ݽ�ȥ��ȡ�������鳤�ȣ�������ȥ������Ϊ����ɣ�����п�����û�кð취��
* ��    ��         : ��
*******************************************************************************/
void Show_bmp(const u8 *dat,u8 wigth)
{
    
  if(t++<wigth)
    show_24high(dat[0+(3*t)],dat[1+(3*t)],dat[2+(3*t)]);
  else t=0;
             
}

void Show_bmp_L(const u8 *dat,u8 wigth)
{
    
  if(t++<wigth)
    show_24high_L(dat[0+(3*t)],dat[1+(3*t)],dat[2+(3*t)]);
  else t=0;
             
}
void Flowing_LED(void)
{
  u8 i=0;
  static u8 a,dat=0x80,dat1=0x80,dat2=0x00,dat3=0x01;
    if(!show_pacg)
    {
      
      if(!hapen_flag)
      {
      hapen_flag = 1;
      dat=0x80;
      dat1=0x80;
      dat2=0x00;
      dat3=0x01;
      }   
        if(++a<30)
        {
          if(a<8)
          {
           dat1>>=1;
          dat3<<=1;
          dat1|=0x80;
          dat3|=0x01; 
          }
          else if(a<15)
          {
          dat1>>=1;
          dat3<<=1;           
          } 
          else if(a<23)
          {
          dat1<<=1;
          dat3>>=1;
          dat1|=0x01;
          dat3|=0x80; 
          }
          else 
          {       
          dat1<<=1;
          dat3>>=1;
          }
        }
        else 
        {
          a =0;         
          dat=0x80;dat1=0x80;dat2=0x00;dat3=0x01;
        }
    }
    else if(show_pacg==1)
    {
    if(!hapen_flag)
    {
    hapen_flag =1;  
    dat=0x00;
    dat1=0x00;
    dat2=0x00;
    dat3=0x01;
    }
        if(++a<48)
        {
          if(a<8)
          {
          dat3<<=1;
          dat3|=0x01; 
          }
          else if(a<16)
          {
            if(a==8)dat2=0x01;
          dat3 = 0xff;  
          dat2<<=1;
          dat2|=0x01;          
          } 
          else if(a<24)
          {
            if(a==16)dat1=0x01;
          dat3 = 0xff;
          dat2 = 0xff;  
          dat1<<=1;
          dat1|=0x01; 
          }
          else if(a<32)
          {      
          dat1 = 0xff;
          dat2 = 0xff;  
          dat3<<=1; 
          }
          else if(a<40)
          {   
          dat1 = 0xff;  
          dat2<<=1; 
          }
          else 
          {                
          dat1<<=1; 
          }
        }
        else 
        {
          a =0;     
          dat=0x00;
          dat1=0x00;
          dat2=0x00;
          dat3=0x01;
        }
    }
     else 
     {
        dat=0x80,dat1=0x80,dat2=0x02,dat3=0x02;
     }
        dat = dat1;
       for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
          {
                
		if(dat>>7)//���ȴ���һ���ֽ��еĸ�λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                    
                  GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
		dat<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	
        dat = dat2;
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat>>7)//���ȴ���һ���ֽ��еĸ�λ
                 GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                    GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
                 
		dat<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
        dat = dat3;
        for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		if(dat>>7)//���ȴ���һ���ֽ��еĵ�λ
                 GPIO_WriteLow(GPIOC,GPIO_PIN_4);
                  else 
                   GPIO_WriteHigh(GPIOC,GPIO_PIN_4);

		dat<<=1;//����λ�ƶ�����λ
                GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		delay_10us(1);
                GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		//delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	GPIO_WriteLow(GPIOC,GPIO_PIN_3);
	delay_10us(1);
	GPIO_WriteHigh(GPIOC,GPIO_PIN_3);//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������


  
  
  
}