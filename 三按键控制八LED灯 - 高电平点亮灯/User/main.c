#include <reg51.h>
void daley(int);
int Key_Scan(void);
void key_catch(int keyValue);
int ledValue = 0x01;
int flickerFlag = 0;
int main()
{
        IT0 = 1;
        IE = 0x81;
                while(1)
                {
                                key_catch(Key_Scan());
                                P1 = ledValue;
                                daley(5);
                                if(flickerFlag != 0)
                                {
                                P1 = 0x00;
                                daley(5);
                                }
                }
}

void daley(t)
        {
                int i,j;
                for (i=t;i>0;i--)
                for (j=1000;j>0;j--);
        }
int Key_Scan(void)
{
                int keyValue = 0x00;
                if(P2 != 0xff)
                {
                                daley(1);
                                if(P2 != 0xff)
                                {
                                                keyValue = P2;
                                                while(P2 != 0xff)
                                                {
                                                                daley(1);
                                                }
                                }
                }
                return keyValue;
}
void key_catch(int keyValue)
{
        switch(keyValue)
        {
                case(0xfe):
                if(ledValue != 0x01)
                {
                        ledValue = ((ledValue) >> 1);
                }
                break;
                                case(0xfd):
                                        flickerFlag = ~flickerFlag;
                                break;
                                                case(0xfb):
                                                if(ledValue != 0x80)
                                                {
                                                        ledValue = ((ledValue) << 1);
                                                }
                                                break;
        }
}