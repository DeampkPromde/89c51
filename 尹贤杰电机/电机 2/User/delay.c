#include "delay.h" 
#include <reg51.h>
void delay(u8 t)
{
        u8 i;
        
        for( t=10; t > 0; t--)
        {
                for(i= 200; i> 0; i--);
        }
}