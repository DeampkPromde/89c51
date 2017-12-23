#include <reg51.h>
#define u8 unsigned char
u8 SegCode[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 KK[6]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
u8 c[6]={2,3,5,9,5,0};
void miedeng();
void dengliang();
void delay(int t);
void yiwei();
void xiaoshi();
void fenzhong();
void jia();
void jian();
char flag=0;
int i,j=0;
u8 num=0;
int main()
{
       IT0=1;
       IE = 0x89;
        while(1)
        {
                dengliang();
                miedeng();
        }
}

int key_press(void)
{
       char key=0xff;
       int i=0;
       if(P2!=0xff)
       {
              delay(1);
              if(P2!=0xff)
              {
                     key=P2;
                     while((i<20)&&(P2!=0xff))
                     {
                            i++;
                            delay(1);
                     }
              }
       }
       return key;
}

void key_control(char key)    //控制按键不同状态对应的不同情况
{
        switch (key)
        {
                case (0xfe):                                    //移位
                {
                        yiwei();
                };
                break;
                
                case (0xfd):                                    //闪烁
                flag=~flag;
                break;
                
                case (0xfb):                                    //加
                if(flag !=0)
                {
                        jia();
                };break;
                
                case (0xf7):                            //减
                if(flag !=0)
                {
                        jian();
                };break;
        }
}

void miedeng ()
{
                if(flag != 0)
                {
                        for(j=10;j>0;j--)
                        {
                                for(i=0;i<6;i++)
                                        {
                                                if (i ==num)
                                                { 
                                                        P1=0xff;
                                                        delay(1);
                                                }
                                                else
                                                {
                                                        if(i==1||i==3)
                                                        {
                                                                P1=KK[i];
                                                                P0= SegCode[c[i]]|0x80;
                                                                delay(1);
                                                        }
                                                        else
                                                        {
                                                                P1=KK[i];
                                                                P0=SegCode[c[i]];
                                                                delay(1);
                                                        }
                                                }
                                        }
                        }
                }
}

void dengliang()
{
        for(j=10;j>0;j--)
             {
                    for(i=0;i<6;i++)
                   { 
                          if(i==1||i==3)
                          {
                                 P1=KK[i];
                                 P0= SegCode[c[i]]|0x80;
                                 delay(1);
                          }
                          else
                          {
                                 P1=KK[i];
                                 P0=SegCode[c[i]];
                                 delay(1);
                          }
                   }
            }
}

void delay(int t)
{
       int i,j;
       for(i=t;i>0;i--)
       for(j=1000;j>0;j--);
}

void xiaoshi()                          //调整小时函数
        {        
                if (c[0]==0||c[0]==1)
                {
                                c[1]+=1;
                                if(c[1]>=10)
                                {
                                c[1]=0;
                                c[0]=c[0]+1;
                                }
                }
                else if (c[0]==2)
                {
                                c[1]+=1;
                                if(c[1]>3)
                                {
                                c[1]=0;
                                c[0]=0;
                                }
                }
        }

void fenzhong()                         //调整分钟函数
        {
                c[3]+=1;
                if(c[3]>=10)
                {
                        c[3]=0;
                        c[2]=c[2]+1;
                        if (c[2]>=6)
                        c[2]=0;
                        xiaoshi();
                }
        }
        
void yiwei()                            //移位函数
{
                if(flag !=0)
                {
                        num+=1;
                        if (num>=6)
                        {
                                num=num-6;
                        }
                }
}

void jia()                              //加函数
{
                switch(num)
                {
                        case(0):                        //第一位是0.1.2
                        {
                                c[num]+=1;
                                if(c[num]>=3)
                                {
                                        c[num]=0;
                                }
                        };break;
                        
                        case(1):                        //第二位
                        {
                                if (c[0]==0||c[0]==1)
                                {
                                        c[num]+=1;
                                        if(c[num]>=10)
                                        {
                                                c[num]=0;
                                                c[num-1]=c[num-1]+1;
                                        }
                                }
                                else if (c[0]==2)
                                {
                                        c[num]+=1;
                                        if(c[num]>3)
                                        {
                                                c[num]=0;
                                                c[num-1]=0;
                                                
                                        }
                                };
                        };break;
                        
                        case(2):
                        {
                                c[num]+=1;
                                if(c[num]>=6)
                                {
                                        c[num]=0;
                                }
                        };break;
                        
                        
                        case(3):
                        {
                                c[num]+=1;
                                if(c[num]>=10)
                                {
                                        c[num]=0;
                                        c[num-1]=c[num-1]+1;
                                        if (c[num-1]>=6)
                                        { 
                                                c[num-1]=0;
                                                xiaoshi();
                                        }
                                }
                        };break;
                        
                        
                        case(4):
                        {
                                c[num]+=1;
                                if(c[num]>=6)
                                {
                                        c[num]=0;
                                }
                        };break;
                        
                        case(5):
                        {
                                c[num]+=1;
                                if(c[num]>=10)
                                {
                                        c[num]=0;
                                        c[num-1]=c[num-1]+1;
                                        if (c[num-1]>=6)
                                        {
                                                c[num-1]=0;
                                                fenzhong();
                                        }
                                        
                                }
                        };break;
                }
}

void jian()                             //减函数
{
                if(c[num]>=1&&c[num]<10)
                {
                        if (num ==0||num==1||num==2||num==3||num==4||num==5)
                        {
                                c[num]=c[num]-1;
                        }
                }
                else
                c[num]=0;
}

void INT0_Handler() interrupt 0
{
       key_control(key_press());
}
