/*
 * Ohm_meter.c
 *
 * Created: 17-May-22 7:10:06 PM
 *  Author: IbrahimElmekawy
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "ADC_driver.h"
#include "LCD.h"
#define F_CPU 8000000UL
int main(void)
{
	long result;
	float v=0 ;
	float vcc = 5 ;
	DDRC=0xff;
	ADC_vinit();
	LCD_vInit();
	LCD_vSend_string("Digital ohmmeter");
	LCD_movecursor(2,1);
	LCD_vSend_string("R=");
	while(1)
	{
		v =((float)(ADC_u16Read()))*0.00488; // 0.00488=(5-0)/1024
		result=(v*10000)/(5-v);
		if(result<10) // from 0 to 9 Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result) + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
			
		}
		else if(result<100) // from 10 to 99 Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result)/10 + 48);
			LCD_vSend_char((result)%10 + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
			
		}
		else if(result<1000) // from 100 to 1K Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result)/100 + 48);
			LCD_vSend_char(((result)%100)/10 + 48);
			LCD_vSend_char((result)%10 + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
			
		}
		else if(result<10000) // from 1K to 9K  Ohm
	    {		
		LCD_movecursor(2,4);
		LCD_vSend_char((result/1000) + 48);
		LCD_vSend_char((result%1000)/100 + 48);
		LCD_vSend_char((((result%1000)%100)/10) + 48);
		LCD_vSend_char((result)%10 + 48);
		LCD_vSend_char(46);
		LCD_vSend_char('0');
		LCD_vSend_char('0');
		LCD_vSend_char(' ');
		LCD_vSend_char(244);
		
		}	
		else if(result<100000) // from 10K to 99K Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result/10000) + 48);
			LCD_vSend_char((result%10000)/1000 + 48);
			LCD_vSend_char((((result%10000)%1000)/100) + 48);
			LCD_vSend_char(((((result%10000)%1000)%100)/10) + 48);
			LCD_vSend_char((result)%10 + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
			
		}
		else if(result<1000000)  // from 100k to 1M Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result/100000) + 48);
			LCD_vSend_char((result%100000)/10000 + 48);
			LCD_vSend_char((((result%100000)%10000)/1000) + 48);
			LCD_vSend_char(((((result%100000)%10000)%1000)/100) + 48);
			LCD_vSend_char((((((result%100000)%10000)%1000)%100)/10) + 48);
			LCD_vSend_char((result)%10 + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
		}	
		else if(result<10000000) // from 1M to 9M Ohm
		{
			LCD_movecursor(2,4);
			LCD_vSend_char((result/1000000) + 48);
			LCD_vSend_char((result%1000000)/100000 + 48);
			LCD_vSend_char((((result%1000000)%100000)/10000) + 48);
			LCD_vSend_char(((((result%1000000)%100000)%10000)/1000) + 48);
			LCD_vSend_char((((((result%1000000)%100000)%10000)%1000)/100) + 48);
			LCD_vSend_char(((((((result%1000000)%100000)%10000)%1000)%100)/10) + 48);
			LCD_vSend_char((result)%10 + 48);
			LCD_vSend_char(46);
			LCD_vSend_char('0');
			LCD_vSend_char('0');
			LCD_vSend_char(' ');
			LCD_vSend_char(244);
		}		
			
		}
			
		
	}
