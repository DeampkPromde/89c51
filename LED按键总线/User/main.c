#include "reg51.h"
int i,botton;
int main()
{
				P0=0xFF;
				while(1)
				{
					botton=P2;
									if( 0xFE == P2) 
									{
														for(i = 100; i > 0; i--);
														if(0xFE== P2)
														{
																		P0=P0^0xFE;
																		P0=~P0;
														}
														while(0xFE == botton); 
										}
								
																	if(0xFD== P2) 
																	{
																			for(i = 100; i > 0; i--);
																				if(0xFD== P2)
																					{
																									P0=P0^0xFD;
																									P0=~P0;
																					}
																			while(0xFD== P2); 
																	}
																	
																										if(0xFB == P2) 
																										{
																												for(i = 100; i > 0; i--);
																													if(0xFB== P2)
																														{
																																		P0=P0^0xFB;
																																		P0=~P0;
																														}
																												while(0xFB== P2);

																										}
																										
																																if(0xF7 == P2) 
																																{
																																		for(i = 100; i > 0; i--);
																																			if(0xF7== P2)
																																				{
																																								P0=P0^0xF7;
																																								P0=~P0;
																																				}
																																		while(0xF7== P2);
																																}
																														
																																								if(0xEF== P2) 
																																								{
																																										for(i = 100; i > 0; i--);
																																											if(0xEF == P2)
																																												{
																																																P0=P0^0xEF;
																																																P0=~P0;
																																												}
																																										while(0xEF == P2);
																																								}
																																								
																																	if(0xDF == P2) 
																																	{
																																			for(i = 100; i > 0; i--);
																																				if(0xDF== P2)
																																					{
																																									P0=P0^0xDF;
																																									P0=~P0;
																																					}
																																			while(0xDF == P2);
																																	}
																																																			
																					if(0xBF== P2) 
																					{
																							for(i = 100; i > 0; i--);
																								if(0xBF == P2)
																									{
																													P0=P0^0xBF;
																													P0=~P0;
																									}
																							while(0xBF == P2);
																					}
																				
								if(0x7F == P2) 
								{
										for(i = 100; i > 0; i--);
											if(0x7F== P2)
												{
																P0=P0^0x7F;
																P0=~P0;
												}
										while(0x7F == P2);

								}

				}
}
