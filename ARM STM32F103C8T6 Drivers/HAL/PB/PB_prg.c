/*
 * PB_prg.c
 *
 *  Created on: Feb 2, 2023
 *  Author: Ahmed Tarek Youssef
 */

#include"STD_TYPES.h"
#include "DIO_interface.h"

#include"PB_pri.h"
#include"PB_config.h"
#include"PB_int.h"


static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}

void H_PB_Void_init(const PB_t* pcopy_PB)
{
	// set direction
	MDIO_voidSetPinDirection(pcopy_PB->PB_port, pcopy_PB->PB_pin, IN_PULL_UP_DOWN) ;

	//MDIO_voidSetPinValue(pcopy_PB->PB_port,pcopy_PB->PB_pin, DIO_HIGH)  ;
}

void H_PB_Void_read(const PB_t* ptr, u8* pvalue)
{
	u8 read ;

	if(ptr->PB_ActiveMode == ACTIVE_LOW)
	{
		*pvalue = NOT_PRESSED_ACTIVE_LOW ;
		// get pin value
		MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;
		if(read == PRESSED_ACTIVE_LOW)
		{
			// debouncing delay
			_delay_ms(30);
			// get 2nd reading to make sure it is not noise
			MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;

			if(read == PRESSED_ACTIVE_LOW)
			{
				while(read == PRESSED_ACTIVE_LOW)
				{
					MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;
				}// while (single press)

				*pvalue = PRESSED_ACTIVE_LOW ;

			}//if 2nd reading is low

		}// if 1st reading is low

	}// if Active_low
	else if(ptr->PB_ActiveMode == ACTIVE_HIGH)
	{
		*pvalue = NOT_PRESSED_ACTIVE_HIGH ;
		// get pin value
		MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;
		if(read == PRESSED_ACTIVE_HIGH)
		{
			*pvalue = PRESSED_ACTIVE_HIGH ;
			// debouncing delay
			_delay_ms(30);
			// get 2nd reading to make sure it is not noise
			MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;
			if(read == PRESSED_ACTIVE_HIGH)
			{
				while(read == PRESSED_ACTIVE_HIGH)
				{
					MDIO_voidGetPinValue(ptr->PB_port, ptr->PB_pin, &read) ;
				}// while (single press)

				*pvalue = PRESSED_ACTIVE_HIGH ;

			}//if 2nd reading is high

		}// if 1st reading is high

	}// if Active_high

}

