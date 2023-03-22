/*
 * ADC_prg.c
 *
 *  Created on: Mar 9, 2023
 *      Author: abdal
 */

	/*******************       Includes      ********************/

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"ADC_pvt.h"
#include	"ADC_config.h"
#include	"ADC_int.h"

	/******************* Functions Definition ********************/
void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}
void	ADC_void_init	(void)
{
	// ON ADC -> ADON -> 1
	SET_BIT(ADC->CR2 , 0);
	_delay_ms(20);

	// Set External event select for regular group -> SWSTART -> 111
	SET_BIT(ADC->CR2 , 19);
	SET_BIT(ADC->CR2 , 17);
	SET_BIT(ADC->CR2 , 18);

	SET_BIT(ADC->CR2 , 20);
	// Set  Data alignment -> Right Alignment -> ALIGN > 0
	CLR_BIT(ADC->CR2 , 11);
	// Set Single conversion mode -> CONT -> 0
	CLR_BIT(ADC->CR2 , 1);
	// Set Channel x Sample time selection -> Default -> 1.5 Cycle

	// Set Number of Conversion in Regular Mode -> Default -> 1


	// Start Calibration -> CAL -> 1
	SET_BIT(ADC->CR2 , 2);
	while(GET_BIT(ADC->CR2 , 2) != 0);

}
u16		ADC_u16_read	(Channel_ID Copy_enuChannel)
{
	u32 Local_u32Reading;
	// Set Channel
	if(Copy_enuChannel <= CHANNEL_9)
	{

		//ADC->SQR3 &= 0xfffffff0; // Clear 0 -> 4 bits
		//ADC->SQR3 |= Copy_enuChannel;
		CLR_BIT(ADC->SQR3 , 0);
		CLR_BIT(ADC->SQR3 , 1);
		CLR_BIT(ADC->SQR3 , 2);
		CLR_BIT(ADC->SQR3 , 3);
		CLR_BIT(ADC->SQR3 , 4);

	}

	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC->CR2 , 22);
	// Wait until the end of conversion -> SWSTART -> 0
	//while(GET_BIT(ADC->CR2 , 22) == 1);

	while(GET_BIT(ADC->SR , 1) != 1);

/*
	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC->CR2 , 0);
	// Wait until the end of conversion -> SWSTART -> 0
	while(GET_BIT(ADC->SR , 1) != 1);
*/
	// Get data -> 0 -> 15
//	Local_u32Reading = (ADC->DR) & 0x0000ffff;
	// Return Data
	return ADC->DR;
}
