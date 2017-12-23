#include <reg52.h>
#include "bsp_key.h"
#include "bsp_delay.h"
sbit MA = P2^0; 
sbit MB = P2^7; //������������� A ��� B ��
u8 shi=5,ge=0,duty_A=0,duty_B=1,i=0,location=50;
/**  �����Ķ���
 *  @param shi       �������ʾռ�ձȵ�ʮλ 
 *  @param ge        �������ʾռ�ձȵĸ�λ
 *  @param duty_A    A ��ĵ�ƽ״̬ 
 *  @param duty_B    B ��ĵ�ƽ״̬
 *  @param i         ��ʱ���ļ���ֵ PWM ��������
 *  @param location  ռ�ձȵ�ֵ
**/
unsigned  char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
                        0x7d,0x07,0x7f,0x6f};//��ѡ����ߵ�ƽ��Ч  ���������
unsigned  char wei[]={0xff,0xfe,0xfd};  //λѡ���飨ֻ������λ��ֻд��������
void main()
{
        
        TMOD=0x01;      //ȷ����ʱ����ʽ
        TH0=0xFC;       //����ֵ
        TL0=0x18;       //����ֵ
        TR0=1;          //����ʱ��
        IE = 0x83;      //ʹ���ⲿ�ж�0�Ƕ�ʱ������ж�0
        
        
        while(1)
        {
                MA=duty_A;      //����ƽ��ֵ�������������
                MB=duty_B;      //����ƽ��ֵ�������������
                
                P1=wei[1];      //��̬ɨ��λѡ
                P0=table[shi];  //��̬ɨ���ѡ
                delay(10);
            
                P1=wei[2];
                P0=table[ge];
                delay(10);
        }
}
/**
 * @brief   �ⲿ�ж�0
 * @retval  null  ���ж�һ�㲻��Ҫ����ֵ��
 */
void INT0_Handler()  interrupt 0
{
        key_scan();
}
/**
 * @brief   ��ʱ������ж�0
 * @retval  null  ���ж�һ�㲻��Ҫ����ֵ��
 */
void TIM0_Handler() interrupt 1
{
        TR0=0; 
        TH0=0xFC;  //��ʱ��1�Ĺ�����ʽʹ����16λ�ļĴ���
        TL0=0x18;  //���Բ����Զ���װ��ֻ���ֶ�װ��
        TR0=1;
        i++;       //��¼���жϵĴ���������û��ʲô�ã�
        
        if(i<location)          //�� duty_A Ϊ 0 ʱ location ����ռ�ձ�
        {                       //_________________ A��
                duty_B=1;       //-------------____ B��
        }                       //��ƽ���Բ�ͬ������˾ʹ��ڵ��Ʋ�
        else if(i>location)     //����ת��
        {
                duty_B=0;
        }
        if(i>=100)              //���� 100 ���� 0 100 ���� PWM ��������
        {
                i=0;
        }
        
}
