#include <reg51.h>
void daley(char);
char Key_Scan(void);
void key_catch(char keyValue);
unsigned char ledValue = 0xfe;
char flickerFlag = 0;
int main()
{
                while(1)
                {
                                key_catch(Key_Scan());
                                P0 = ledValue;
                                daley(5);
                                if(flickerFlag != 0)
                                {
                                P0 = 0xff;
                                daley(5);
                                }
                }
}

void daley(char t)
        {
                char i,j;
                for (i=t;i>0;i--)
                for (j=1000;j>0;j--);
        }
char Key_Scan(void)
{
                char keyValue = 0xff;
                if(P2 != 0xff)
                {
                        int i;
                                daley(5);
                                if(P2 != 0xff)
                                {
                                                keyValue = P2;
                                                while(i<20&&P2 != 0xff);
                                        {
                                        daley(8);
                                                i++;
                                        }
                                }
                }
                return keyValue;
}
void key_catch(char keyValue)
{
        switch(keyValue)
        {
                case(0xfe):
                if(ledValue != 0xfe)
                {
                        ledValue = ~((~ledValue) >> 1);
                }
                break;
                                case(0xfd):
                                        flickerFlag = ~flickerFlag;
                                break;
                                                case(0xfb):
                                                if(ledValue != 0x7f)
                                                {
                                                        ledValue =~((~ledValue) << 1);
                                                }
                                                break;
        }
}