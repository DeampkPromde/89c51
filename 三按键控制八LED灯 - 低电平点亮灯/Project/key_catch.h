#ifndef __BSP_KEY_CATCH_H
#define __BSP_KEY_CATCH_H
void key_catch()
switch(keyValue)
{
                case(0xfe):
                if(ledValue != 0xfe)
                {
                        ledValue = ~(~(ledValue) >> 1);
                }
                break;
                                case(0xfd):
                                        flickerFlag = ~flickerFlag;
                                break;
                                                case(0xfb):
                                                if(ledValue != 0x7f)
                                                {
                                                        ledValue = ~(~(ledValue) << 1);
                                                }
                                                break;
        }
}