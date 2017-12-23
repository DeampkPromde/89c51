#include "bsp_delay.h" 
#include <reg52.h>
void delay(u8 ms)
{
        u8 temp;
        
        for( ms=10; ms > 0; ms--)
        {
                for(temp = 200; temp > 0; temp--);
        }
}