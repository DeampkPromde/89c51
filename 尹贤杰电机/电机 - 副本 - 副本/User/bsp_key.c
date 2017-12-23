#include <reg52.h>
#include "bsp_key.h" 
#include "bsp_delay.h" 
sbit K1 = P2^1;
sbit K2 = P2^2;
sbit K3 = P2^3;
sbit K4 = P2^4;
sbit MA = P2^0;
sbit MB = P2^7;
u8 flag=0,flag_s=0; //flag是正反转的标志位 0 代表逆时针 1 代表顺时针
                    //flag_s是启停标志位（star   stop）0 代表 star 1 代表 stop
extern u8 ge,shi,location,duty_A,duty_B;  // 外部变量的声明
/**
 * @brief 按键的扫描
 * @retval null
 */ 
void key_scan()
{
        u8 ge_t,shi_t; //局部变量用于存储数码管的值
        if(0 == K1)
        {
                // 按键消抖
                delay(5);
                if(0 == K1);
                {
                        switch(flag_s)
                        {
                                case(0):
                                  ET0=0;        //关定时器 定时器一关就没有谁可以改变duty_B
                                  duty_A=0;     //两相没有电势差电机不会转动
                                  duty_B=0;
                                  
                                  ge_t=ge;      //临时存储数码管的值
                                  shi_t=shi;
                                  
                                  ge=0;         //电机不转占空比为0
                                  shi=0;
                                  flag_s=1;
                                break;
                                case(1):
                                  ET0=1;        //开定时器
                                  ge=ge_t;      //恢复数码管的显示
                                  shi=shi_t;
                                  if(flag==1)   //如果是顺时针的话 duty_A 置 1 
                                  {
                                          duty_A=1;
                                  }
//                                 else        //这段代码可以不要放在这里为了更好理解
//                                  {
//                                          duty_A=0;
//                                  }
                                  flag_s=0;
                                break;
                                
                        }
                        
                }
                
                // 松手检测
                while(0 == K1);
        }
        
        if(0 == K2)
        {
                // 按键消抖
                delay(5);
                if(0 == K2);
                {
                        if(0==flag_s) //只有在转动的状态下才能改变转动的方向
                        {
                                switch(flag)
                                {
                                        case(0):                  //如果现在是逆时针则改变成顺时针 duty_A 置 1
                                          duty_A=1;               //改变前 PWM 示意图（以占空比 80% 为例）
                                          location=100-location;  //__________________A相
                                          flag=1;                 //--------------____B相
                                        break;                    //location=100-location  这句代码后占空比变成 20%
                                        case(1):                  //------------------A相
                                          duty_A=0;               //----______________B相
                                          location=100-location;  //占空比虽然变成 20% 但电势差存在的时间依然为 80%
                                          flag=0;                 //转速不变，方向却反了
                                        break;                    
                                }
                        }
                }
                // 松手检测w
                while(0 == K2);
        }
        
        if(0 == K3)
        {
                // 按键消抖
                delay(5);
                if(0 == K3);
                {
                        if(flag_s==0)  //只有在转动的状态下才能改变占空比的大小
                        {
                                if((shi*10+ge)<97)  //数码管的进位
                                {
                                        ge+=3;
                                        if(ge>=10)
                                        {
                                                ge-=10;
                                                shi+=1;
                                        }
                                }
                                if((flag==0)&&location<97)     //逆时针状态下占空比加 3 
                                {                              //__________________A相
                                        location+=3;           //--------------____B相
                                }
                                else if ((flag!=0)&&location>3)//顺时针状态下占空比减 3
                                {                              //------------------A相 
                                        location-=3;           //----______________B相
                                }                              //占空比虽然小了但电势差存在的时间却变长了
                        }
                }
                
                // 松手检测
                while(0 == K3);
        }
        
        if(0 == K4)
        {
                // 按键消抖
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
                                
                                if((flag==0)&&location>5)
                                {
                                        location-=5;
                                }
                                else if((flag!=0)&&location<95)
                                {
                                        location+=5;
                                }
                        }
                }
                
                // 松手检测
                while(0 == K4);
        }
}