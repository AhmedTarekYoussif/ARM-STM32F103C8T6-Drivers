/*
 * EXTI_private.h
 *
 *  Created on: Mar 6, 2023
 *      Author: mohamed
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#include "STD_TYPES.h"
typedef	struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RSTR;
	volatile	u32		FSTR;
	volatile	u32		SWIER;
	volatile	u32		PR;
}EXTI_Type ;

/*		EXTI -> EMR = xxxx;	*/
#define		EXTI	((EXTI_Type *)0x40010400)

#endif /* EXTI_EXTI_PRIVATE_H_ */
