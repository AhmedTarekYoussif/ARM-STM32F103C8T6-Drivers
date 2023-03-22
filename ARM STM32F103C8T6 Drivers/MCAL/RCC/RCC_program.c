#include	"STD_TYPES.h"
#include	"BIT_MATH.h"


#include	"RCC_interface.h"
#include	"RCC_private.h"
#include	"RCC_config.h"



void	MRCC_voidSysClkInit(void)
{
	#if			SYSTEM_CLK	==	RCC_HSI
				SET_BIT(RCC_CR,0);
				CLR_BIT(RCC_CFGR,0);
				CLR_BIT(RCC_CFGR,1);
	#elif		SYSTEM_CLK	==	RCC_HSE
				SET_BIT(RCC_CR,16);
				SET_BIT(RCC_CFGR,0);
				CLR_BIT(RCC_CFGR,1);
	#elif		SYSTEM_CLK	==	RCC_PLL	
				SET_BIT(RCC_CR,25);
				CLR_BIT(RCC_CFGR,0);
				SET_BIT(RCC_CFGR,1);
	#else
		#error	"Wrong choice of RCC clock type"
	#endif
}
void	MRCC_voidEnablePerClk(u8 PerBus,u8 PerNum)
{
	/*	Range Check						*/
	if(PerNum<32)
	{
		switch(PerBus)
		{
			case RCC_AHB	:	SET_BIT(RCC_AHBENR ,PerNum);	break;
			case RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerNum);	break;
			case RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerNum);	break;
		}
	}
	else
	{/*		Report Error 			*/}	
}
void	MRCC_voidDisablePerClk(u8 PerBus,u8 PerNum)
{
		/*	Range Check						*/
	if(PerNum<32)
	{
		switch(PerBus)
		{
			case RCC_AHB	:	CLR_BIT(RCC_AHBENR ,PerNum);	break;
			case RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerNum);	break;
			case RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerNum);	break;
		}
	}
	else
	{/*		Report Error 			*/}
}




