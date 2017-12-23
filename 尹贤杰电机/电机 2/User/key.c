#include <reg51.h>
#include "key.h" 
#include "delay.h" 
sbit K1 = P2^1;
sbit K2 = P2^2;
sbit K3 = P2^3;
sbit K4 = P2^4;
sbit MA = P2^0;
sbit MB = P2^7;
u8 flag=0,flag_s=0;
extern u8 ge,shi,zhankongbi,duty_A,duty_B;

void key()
{
        u8 ge_t,shi_t;
        if(0 == K1)
        {
                delay(5);
                if(0 == K1);
                {
                        switch(flag_s)
                        {
                                case(0):
                                  ET0=0;
                                  duty_A=0;
                                  duty_B=0;
                                  
                                  ge_t=ge;
                                  shi_t=shi;
                                  
                                  ge=0;
                                  shi=0;
                                  flag_s=1;
                                break;
                                case(1):
                                  ET0=1;
                                  ge=ge_t;
                                  shi=shi_t;
                                  if(flag==1)
                                  {
                                          duty_A=1;
                                  }
                                  flag_s=0;
                                break;
                                
                        }
                }
                while(0 == K1);
        }
        
        if(0 == K2)
        {
                delay(5);
                if(0 == K2);
                {
                        if(0==flag_s)
                        {
                                switch(flag)
                                {
                                        case(0):
                                          duty_A=1;
                                          zhankongbi=100-zhankongbi;
                                          flag=1;
                                        break;
                                        case(1):
                                          duty_A=0;
                                          zhankongbi=100-zhankongbi;
                                          flag=0;
                                        break;
                                }
                        }
                }
                while(0 == K2);
        }
        
        if(0 == K3)
        {
                delay(5);
                if(0 == K3);
                {
                        if(flag_s==0)
                        {
                                if((shi*10+ge)<97)
                                {
                                        ge+=3;
                                        if(ge>=10)
                                        {
                                                ge-=10;
                                                shi+=1;
                                        }
                                }
                                if((flag==0)&&zhankongbi<97)
                                {
                                        zhankongbi+=3;
                                }
                                else if ((flag!=0)&&zhankongbi>3)
                                {
                                        zhankongbi-=3;
                                }
                        }
                }
                while(0 == K3);
        }
        
        if(0 == K4)
        {
                delay(5);
                if(0 == K4);
                {
                        if(0==flag_s)
                        {
                                if((shi*10+ge)>5)
                                {
                                        if(ge>=5)
                                        {
                                                ge-=5;
                                        }
                                        else
                                        {
                                                ge+=10;
                                                ge-=5;
                                                shi-=1;
                                        }
                                        
                                }
                                
                                if((flag==0)&&zhankongbi>5)
                                {
                                        zhankongbi-=5;
                                }
                                else if((flag!=0)&&zhankongbi<95)
                                {
                                        zhankongbi+=5;
                                }
                        }
                }
                while(0 == K4);
        }
}