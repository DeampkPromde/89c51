#include <reg51.h>
int a,t,m;
sbit led = P1^0;
void Key_led ();
void Delay(int t);
void Control_led();
int main ()
{
        IP=0X04;
        IT0=1;
        TMOD = 0x01;
        TH0 = 0x0b;
        TL0 = 0xdc;
        TR0 = 1;
        IE = 0x86;
        led = 1;
        m = 0;
        while(1)
        {
        
        }
}

void Delay(int t)
{
        int i,j;
        for(i=t;i>0;i--)
        for (j=1000;j>0;j--);
}

void TIM0_Handler() interrupt 1
{
        TR0 = 0;
        TH0 = 0x0b;
        TL0 = 0xdc;
        TR0 = 1;
        a++;
        if(a >=16)
        {
                a = 0;
                led = ~led;
                if(led==0)
                {
                        Delay(1000);
                }
        }
}

void TIN0_Handler() interrupt 2
{
        led = 1;
        Delay(1000);
}