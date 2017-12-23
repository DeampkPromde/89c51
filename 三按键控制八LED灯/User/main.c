#include <reg51.h>
void daley(unsigned char);
unsigned char Key_Scan(void);
void key_catch(unsigned char keyValue);
unsigned char ledValue = 0xfe;
unsigned char flickerFlag = 0;
int main()
{
                while(1)
                {
                        
                key_catch(Key_Scan());  //��״̬
                        P0=ledValue;
                        daley(5);
                        if (flickerFlag!=0)  //���Ƶ���˸
                        {
                                P0=0xff;
                                daley(5);
                        }
                }
}
void daley(unsigned char t)
        {
                unsigned char i,j;        //�ӳٺ���
                for (i=t;i>0;i--)
                for (j=1000;j>0;j--);
        }

unsigned char Key_Scan(void)            //��׽����ֵ
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
void key_catch(unsigned char keyValue)    //���ư�����ͬ״̬��Ӧ�Ĳ�ͬ���
{
        switch (keyValue)
        {
                case (0xfe):
                        if (ledValue !=0x7f)
                        {
                                ledValue=~((~ledValue)<<1);
                        };break;
                
                case (0xfd):
                flickerFlag=~flickerFlag;
                        daley (1);break;
                
                case (0xfb):
                if (ledValue !=0xfe)
                {
                ledValue=~((~ledValue)>>1);
                };break;
        }
}