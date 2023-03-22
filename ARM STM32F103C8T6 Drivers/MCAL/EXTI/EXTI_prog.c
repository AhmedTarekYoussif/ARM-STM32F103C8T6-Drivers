/*
 * EXTI_prog.c
 *
 *  Created on: Mar 6, 2023
 *      Author: mohamed
 */

#ifndef EXTI_EXTI_PROG_C_
#define EXTI_EXTI_PROG_C_

#include	"STD_Types.h"
#include	"BIT_Math.h"

#include    "EXTI_init.h"
#include    "EXTI_private.h"
#include	"INVIC_init.h"
#include	"INVIC_private.h"
#include	"INVIC_config.h"


#ifndef		NULL
#define		NULL	(void *)0
#endif

static void (*EXTI0_CallBack) (void) = NULL;



void	EXTI_voidInit(void)
{

}

void	EXTI_voidEnableLine(u8 ExtiLine)
{
	SET_BIT(EXTI -> IMR , ExtiLine);
}

void	EXTI_voidDisableLine(u8 ExtiLine)
{
	CLR_BIT(EXTI -> IMR , ExtiLine);
}

void	EXTI_voidSetExtiEdge(u8 ExtiLine,u8 edge)
{
	switch(edge)
	{
		case	EXTI_RISING	:		SET_BIT(EXTI -> RSTR,ExtiLine);
									CLR_BIT(EXTI -> FSTR,ExtiLine);
		break;

		case	EXTI_FALLING:		SET_BIT(EXTI -> FSTR,ExtiLine);
									CLR_BIT(EXTI -> RSTR,ExtiLine);
		break;

		case	EXTI_IOC	:		SET_BIT(EXTI -> RSTR,ExtiLine);
									SET_BIT(EXTI -> FSTR,ExtiLine);
		break;
		default:
									CLR_BIT(EXTI -> RSTR,ExtiLine);
									CLR_BIT(EXTI -> FSTR,ExtiLine);
	}
}

void	EXTI_voidSetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI0_CallBack = Pf; //Ahmed
	}
}

//External Peripherals
void	EXTI0_IRQHandler(void)
{
	//EXTI0_CallBack(); // Ahmed();
	if(GET_BIT(EXTI -> PR , 0) != 0)
	{
		SET_BIT(EXTI -> PR , 0);
		EXTI0_CallBack();
	}
}




#endif /* EXTI_EXTI_PROG_C_ */
