/*
 * ADC_pvt.h
 *
 *  Created on: Mar 9, 2023
 *      Author: abdal
 */

#ifndef ADC_PVT_H_
#define ADC_PVT_H_

	/*******************       Registers      ********************/

typedef	struct
{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR1;
	volatile u32 JOFR2;
	volatile u32 JOFR3;
	volatile u32 JOFR4;
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR1;
	volatile u32 SQR2;
	volatile u32 SQR3;
	volatile u32 JSQR;
	volatile u32 JDR1;
	volatile u32 JDR2;
	volatile u32 JDR3;
	volatile u32 JDR4;
	volatile u32 DR;
}ADC_Type;

#define		ADC	((ADC_Type *)0x40012400)

	/*******************    Private Macros    ********************/


#endif /* ADC_PVT_H_ */
