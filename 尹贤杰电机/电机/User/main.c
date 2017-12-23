#include <reg51.h>
#define u8 unsigned char
u8 Xianshi[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};             //0.1.2.3.4.5.6..7.8.9
u8 Weixuan[2]={0xfe,0xfd};                                                      //开启第一位或者第二位
u8 c[2]={5,0};                                                                      //初始50
sbit key = P2^1;
sbit key1 = P2^2;
sbit key2 = P2^3;
sbit key3 = P2^4;
sbit zhuan = P2^0;
sbit zhuan1 = P2^6;
int i,j,t,num,k=0;
void delay(int t);
void gongneng();
void dengliang();
void jia();
void jian();
void zhuanji();
u8 pinlv();
int main ()
{
       IT0=1;
       IE = 0x81;
        num=50;
        P2==0xff;
        while(1)
        {
                dengliang();
                zhuanji();
        }
}

void gongneng()
{
        if ( key==0||key1 ==0||key2==0||key3==0)
        {
                delay(1);
                {
                        if (key==0)
                        {
                                if(k==0)
                                {
                                zhuan=~zhuan;
                                        k=~k;
                                }
                                else if(k!=0)
                                {
                                        zhuan=zhuan1=1;
                                        k=~k;
                                }
                        }
                        else if ((zhuan==1&&zhuan1==0||zhuan==0&&zhuan1==1)&&key1==0)
                        {
                                zhuan = ~zhuan;
                                zhuan1 = ~zhuan1;
                        }
                        else if ((zhuan==1&&zhuan1==0||zhuan==0&&zhuan1==1)&&key2==0)
                        {
                                        if(num<=96)
                                        {
                                                num+=3;
                                        }
                                        if(num>96)
                                        {
                                                num=num;
                                        }
                                        jia();
                        }
                        else if ((zhuan==1&&zhuan1==0||zhuan==0&&zhuan1==1)&&key3==0)
                        {
                                        if(num>=5)
                                        {
                                        num-=5;
                                        }
                                        if(num<5)
                                        {
                                                num=num;
                                        }
                                        jian();
                        }
                }
        }
}


void zhuanji ()
{
        if(zhuan==1&&zhuan1!=1)
        {
                        j=100-num;
                for(i=j;i>=0;i--)
                {
                        delay(2);
                }
                        P2=0xff;
                for(i=j;i>0;i--)
                {
                        delay(2);
                }
                        zhuan1=0;
        }
        if(zhuan1==1&&zhuan!=1)
        {
                for(i=num;i>=0;i--)
                {
                        delay(2);
                }
                        j=100-num;
                        P2=0xff;
                for(i=j;i>0;i--)
                {
                        delay(2);
                }
                        zhuan=0;
        }
}

void dengliang()
{
        for(j=10;j>0;j--)
             {
                    for(i=0;i<2;i++)
                   {
                                P1=Weixuan[i];
                                P0=Xianshi[c[i]];
                                delay(50);
                   }
            }
}

void jia()                                                //加函数
{
        if(c[0]<9)
        {
                c[1]=c[1]+3;
                if(c[1]>9)
                {
                        c[1]=c[1]-10;
                        c[0]=c[0]+1;
                }
        }
        if(c[0]>=9)
        {
        c[0]=9;
                if(c[1]>=9)
                {
                        c[1]=9;
                }
                if(c[1]<7)
                {
                        c[1]=c[1]+3;
                }
        }
}

void jian()                                                //减函数
{
        if(c[1]>=5)
        {
                c[1]=c[1]-5;
        }
        else if(c[1]<5&&c[1]>=0)
        {
                if(c[0]==0)
                {
                        c[1]=c[1];
                        c[0]=0;
                }
                else
                {
                        c[1]=c[1]+5;
                        c[0]=c[0]-1;
                }
        }
}

void delay(int t)
{
        int i,j;
        for (i=t;i>0;i--)
                for (j=10;j>0;j--);
}


void INT0_Handler() interrupt 0
{
        gongneng();
}
