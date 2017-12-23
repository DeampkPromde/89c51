#include <reg52.h>
#include "bsp_key.h" 
#include "bsp_delay.h" 
sbit K1 = P2^1;
sbit K2 = P2^2;
sbit K3 = P2^3;
sbit K4 = P2^4;
sbit MA = P2^0;
sbit MB = P2^7;
u8 flag=0,flag_s=0; //flag������ת�ı�־λ 0 ������ʱ�� 1 ����˳ʱ��
                    //flag_s����ͣ��־λ��star   stop��0 ���� star 1 ���� stop
extern u8 ge,shi,location,duty_A,duty_B;  // �ⲿ����������
/**
 * @brief ������ɨ��
 * @retval null
 */ 
void key_scan()
{
        u8 ge_t,shi_t; //�ֲ��������ڴ洢����ܵ�ֵ
        if(0 == K1)
        {
                // ��������
                delay(5);
                if(0 == K1);
                {
                        switch(flag_s)
                        {
                                case(0):
                                  ET0=0;        //�ض�ʱ�� ��ʱ��һ�ؾ�û��˭���Ըı�duty_B
                                  duty_A=0;     //����û�е��Ʋ�������ת��
                                  duty_B=0;
                                  
                                  ge_t=ge;      //��ʱ�洢����ܵ�ֵ
                                  shi_t=shi;
                                  
                                  ge=0;         //�����תռ�ձ�Ϊ0
                                  shi=0;
                                  flag_s=1;
                                break;
                                case(1):
                                  ET0=1;        //����ʱ��
                                  ge=ge_t;      //�ָ�����ܵ���ʾ
                                  shi=shi_t;
                                  if(flag==1)   //�����˳ʱ��Ļ� duty_A �� 1 
                                  {
                                          duty_A=1;
                                  }
//                                 else        //��δ�����Բ�Ҫ��������Ϊ�˸������
//                                  {
//                                          duty_A=0;
//                                  }
                                  flag_s=0;
                                break;
                                
                        }
                        
                }
                
                // ���ּ��
                while(0 == K1);
        }
        
        if(0 == K2)
        {
                // ��������
                delay(5);
                if(0 == K2);
                {
                        if(0==flag_s) //ֻ����ת����״̬�²��ܸı�ת���ķ���
                        {
                                switch(flag)
                                {
                                        case(0):                  //�����������ʱ����ı��˳ʱ�� duty_A �� 1
                                          duty_A=1;               //�ı�ǰ PWM ʾ��ͼ����ռ�ձ� 80% Ϊ����
                                          location=100-location;  //__________________A��
                                          flag=1;                 //--------------____B��
                                        break;                    //location=100-location  �������ռ�ձȱ�� 20%
                                        case(1):                  //------------------A��
                                          duty_A=0;               //----______________B��
                                          location=100-location;  //ռ�ձ���Ȼ��� 20% �����Ʋ���ڵ�ʱ����ȻΪ 80%
                                          flag=0;                 //ת�ٲ��䣬����ȴ����
                                        break;                    
                                }
                        }
                }
                // ���ּ��w
                while(0 == K2);
        }
        
        if(0 == K3)
        {
                // ��������
                delay(5);
                if(0 == K3);
                {
                        if(flag_s==0)  //ֻ����ת����״̬�²��ܸı�ռ�ձȵĴ�С
                        {
                                if((shi*10+ge)<97)  //����ܵĽ�λ
                                {
                                        ge+=3;
                                        if(ge>=10)
                                        {
                                                ge-=10;
                                                shi+=1;
                                        }
                                }
                                if((flag==0)&&location<97)     //��ʱ��״̬��ռ�ձȼ� 3 
                                {                              //__________________A��
                                        location+=3;           //--------------____B��
                                }
                                else if ((flag!=0)&&location>3)//˳ʱ��״̬��ռ�ձȼ� 3
                                {                              //------------------A�� 
                                        location-=3;           //----______________B��
                                }                              //ռ�ձ���ȻС�˵����Ʋ���ڵ�ʱ��ȴ�䳤��
                        }
                }
                
                // ���ּ��
                while(0 == K3);
        }
        
        if(0 == K4)
        {
                // ��������
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
                
                // ���ּ��
                while(0 == K4);
        }
}