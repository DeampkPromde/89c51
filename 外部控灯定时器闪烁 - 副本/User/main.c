#include <reg51.h>
int a,t,m;
sbit led = P2^0;
void Key_led ();
void Delay(int t);
void Control_led();
int main ()
{
        IP=0X08;
        IT0=1;
        TMOD = 0x10;
        TH1 = 0x0b;
        TL1 = 0xdc;
        TR1 = 1;
        IE = 0x89;
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
        for (j=100;j>0;j--);
}

void TIN0_Handler() interrupt 0
{
        led = 1;
        Delay(1000);
}
void TIM0_Handler() interrupt 3
{
        
        TR1=0;
        TH1 = 0x0b;
        TL1 = 0xdc;
        TR1=1;
        a++;
        if(a >=16)
        {
                a = 0;
                led = ~led;
        }
}