#include<reg51.h>
sbit wei=P1^0;
int j;
void delay(int j);
int main()
{
        while(1)
        {
                wei=5;
                delay(10);
                wei=0;
                delay(10);
        }
}

void delay(int j)
{
        int i;
        for (j;j>0;j--)
        {
                for(i=1000000;i>0;i--);
        }
}