#include <reg51.h>
#include "key.h"
#include "delay.h"
sbit MA = P2^0; 
sbit MB = P2^7; 
u8 shi=5,ge=0,duty_A=0,duty_B=1,i=0,zhankongbi =50;
u8 table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 wei[]={0xfe,0xfd};
void main()
{
        
        TMOD=0x01;
        TH0=0xFC;
        TL0=0x18;
        TR0=1;
        IE = 0x83;

        while(1)
        {
                MA=duty_A;
                MB=duty_B;
                
                P1=wei[0];
                P0=table[shi];
                delay(10);
            
                P1=wei[1];
                P0=table[ge];
                delay(10);
        }
}


void INT0_Handler()  interrupt 0
{
        key();
}


void TIM0_Handler() interrupt 1
{
        TR0=0; 
        TH0=0xFC;
        TL0=0x18;
        TR0=1;
        i++;
        if(i<zhankongbi)
        {
                duty_B=1;
        }
        else if(i>zhankongbi)
        {
                duty_B=0;
        }
        if(i>=100)
        {
                i=0;
        }
}
