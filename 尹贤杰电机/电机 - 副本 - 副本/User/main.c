#include <reg52.h>
#include "bsp_key.h"
#include "bsp_delay.h"
sbit MA = P2^0; 
sbit MB = P2^7; //电机的两个引脚 A 相和 B 相
u8 shi=5,ge=0,duty_A=0,duty_B=1,i=0,location=50;
/**  变量的定义
 *  @param shi       数码管显示占空比的十位 
 *  @param ge        数码管显示占空比的个位
 *  @param duty_A    A 相的电平状态 
 *  @param duty_B    B 相的电平状态
 *  @param i         定时器的计数值 PWM 波的周期
 *  @param location  占空比的值
**/
unsigned  char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
                        0x7d,0x07,0x7f,0x6f};//段选数组高电平有效  共阴数码管
unsigned  char wei[]={0xff,0xfe,0xfd};  //位选数组（只用了两位就只写的三个）
void main()
{
        
        TMOD=0x01;      //确定定时器方式
        TH0=0xFC;       //赋初值
        TL0=0x18;       //赋初值
        TR0=1;          //开定时器
        IE = 0x83;      //使能外部中断0是定时器溢出中断0
        
        
        while(1)
        {
                MA=duty_A;      //将电平的值赋给具体的引脚
                MB=duty_B;      //将电平的值赋给具体的引脚
                
                P1=wei[1];      //动态扫描位选
                P0=table[shi];  //动态扫描段选
                delay(10);
            
                P1=wei[2];
                P0=table[ge];
                delay(10);
        }
}
/**
 * @brief   外部中断0
 * @retval  null  （中断一般不需要返回值）
 */
void INT0_Handler()  interrupt 0
{
        key_scan();
}
/**
 * @brief   定时器溢出中断0
 * @retval  null  （中断一般不需要返回值）
 */
void TIM0_Handler() interrupt 1
{
        TR0=0; 
        TH0=0xFC;  //定时器1的工作方式使用了16位的寄存器
        TL0=0x18;  //所以不能自动重装载只能手动装载
        TR0=1;
        i++;       //记录进中断的次数（好像并没有什么用）
        
        if(i<location)          //当 duty_A 为 0 时 location 代表占空比
        {                       //_________________ A相
                duty_B=1;       //-------------____ B相
        }                       //电平极性不同电机两端就存在电势差
        else if(i>location)     //才能转动
        {
                duty_B=0;
        }
        if(i>=100)              //到了 100 就清 0 100 代表 PWM 波的周期
        {
                i=0;
        }
        
}
