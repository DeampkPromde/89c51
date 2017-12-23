#ifndef __BSP_KEY_SCAN_H
#define __BSP_KEY_SCAN_H
int Key_Scan(void)
{
                int keyValue = 0xff;
                int i = 0;
                if(P2 != 0xff)
                {
                                delay(1);
                                if(P2 != 0xff)
                                {
                                                keyValue = P2;
                                                while((i < 20) && (P2 != 0xff))
                                                {
                                                                delay(1);
                                                i++;
                                                }
                                }
                }
                return keyValue;
}