#include <reg51.h>
#define u8 unsigned char;
u8 a;
sbit led=P0^0;
int main ()
{
        TMOD = 0x10;
        TH1 = 0x0b;
        TL1 = 0xdc;
        IE = 0x88;
        TR1 = 1;
        led = 0;
        while(1);
}

void TIM0_Handler() interrupt 3
{
        TR1 = 0;
        TH1 = 0x0b;
        TL1 = 0xdc;
        TR1 = 1;
        a++;
        if(a >= 16)
        {
        a = 0;
        led = ~led;
}
}