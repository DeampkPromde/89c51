#include "reg51.h"
void delay()
{
	int a;
	for (a=10000;a>0;a--);
}
	
int main()
{
		int m;
		while(1)
		{	
					P0 = 0xFE;
					delay();
									for(m=1;m<8;m++)
												{	
															P0 = ~P0;  
															P0 = P0 << 1;
															P0 = ~P0;	
															delay();
												}
		}
}