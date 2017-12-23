#include <reg51.h>
void daley(unsigned char);
unsigned char Key_Scan(void);
void key_catch(unsigned char keyValue);
sbit led=P0^0;
sbit led1=P0^1;
sbit led2=P0^2;
sbit led3=P0^3;
sbit led4=P0^4;
sbit led5=P0^5;
sbit led6=P0^6;
sbit led7=P0^7;
int main()
{
        IT1 = 1;
        IE = 0x84;
                        led=1;
                        led1=1;
                        led2=1;
                        led3=1;
                        led4=1;
                        led5=1;
                        led6=1;
                        led7=1;
                while(1)
                {
                        
                        daley(5);
                }
}
void daley(unsigned char t)
        {
                unsigned char i,j;        //延迟函数
                for (i=t;i>0;i--)
                for (j=1000;j>0;j--);
        }

unsigned char Key_Scan(void)            //捕捉按键值
{
                unsigned char keyValue = 0xff;
                if(P2 != 0xff)  
                {
                                daley(5);
                                if(P2 != 0xff)
                                {
                                                keyValue = P2;
                                                while(P2 != 0xff);
                                }
                }
                return keyValue;
}
void key_catch(unsigned char keyValue)    //控制按键不同状态对应的不同情况
{
        switch (keyValue)
        {
                case (0xfe):
                        led=~led;break;
                
                case (0xfd):
                        led1=~led1;break;
                
                case (0xfb):
                        led2=~led2;break;
                
                case (0xf7):
                        led3=~led3;break;
                
                case (0xef):
                        led4=~led4;break;
                
                case (0xdf):
                        led5=~led5;break;
                
                case (0xbf):
                        led6=~led6;break;
                
                case (0x7f):
                        led7=~led7;break;
        }
}

void INT0_Handler() interrupt 2
{
                        key_catch(Key_Scan());

}