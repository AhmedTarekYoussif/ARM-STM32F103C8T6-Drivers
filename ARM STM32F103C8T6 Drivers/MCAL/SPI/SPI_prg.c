/*
 * SPI_prg.c
 *
 *  Created on: Feb 21, 2023
 *      Author: Ahmed Tarek
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_pri.h"
#include"SPI_config.h"
#include"SPI_int.h"
#include"DIO_interface.h"


void MSPI_void_initMaster(void)
{
	SPI_CR1 = 0x0347 ;
}

void MSPI_void_initSlave(void)
{
	SPI_CR1 = 0x0343 ;
}

void MSPI_void_sendByte(u8 copy_u8Byte)
{
	MDIO_voidSetPinValue(PORTA,PIN0,DIO_LOW) ;    /*NSS(PA0)(Active low) = 0 */

	SPI_DR = copy_u8Byte;

	while( GET_BIT(SPI_SR,1) == 0 )
	{
		asm("NOP") ;
	}

#if 0
	SPI_DR = copy_u8Byte;
	while( GET_BIT(SPI_SR,7) == 1 )
	{
		asm("NOP") ;
	}
#endif
	MDIO_voidSetPinValue(PORTA,PIN0,DIO_HIGH) ;    /*NSS(PA0)(Active HIGH) = 1 */

}

void MSPI_void_recieveByte(u8 *copy_u8Byte)
{
	//	MDIO_voidSetPinValue(PORTA,PIN0,DIO_LOW) ;    /*NSS(PA0)(Active low) = 0 */

	while( GET_BIT(SPI_SR,1) == 0 );
	*copy_u8Byte = SPI_DR;

}

void MSPI_void_sendString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		MSPI_void_sendByte(str[i]);
		i++;
	}
}

void MSPI_void_receiveString(u8 *str)
{
	u8 i = 0;
	MSPI_void_recieveByte(&str[i]);
	while(str[i] != '#')
	{
		i++;
		MSPI_void_recieveByte(&str[i]);
	}
	str[i] = '\0';
}
