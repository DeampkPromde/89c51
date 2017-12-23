#include "reg51.h"
int main(void)
{
	int i;
	while(1)
	{	P0 = 10101010;
	for (i=1000000;i>0;i--);
		P0 = 11111111;
	for (i=1000000;i>0;i--);
	}
		;
	
}
