#include <reg51.h>
#define u8 unsigned char
u8 SegCode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
u8 KK[6]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
u8 WW[4]={4,5,0,3};
void delay (int t);
int main ()
{
        int i;
        while(1)
        {
                        for(i=0;i<4;i++)
                        {
                                P1 = KK[i];//位选要放在段选前面
                                P0 = SegCode[WW[i]];
                        delay(1);
                        }
        }

}
void delay(int t)
{
int i, j;
for(i = t; i > 0; i--)
for(j = 100; j > 0; j--);
}