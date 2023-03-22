/*
 * UART_prg.c
 *
 *  Created on: Feb 21, 2023
 *      Author: Ahmed Tarek
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_pri.h"
#include"UART_config.h"
#include"UART_int.h"

void MUSART_void_init(void)
{

    /* Set baud rate = 9600 (DIV_Mantissa = 52 (0x34), DIV_Fraction[3:0] = 1(0x1))*/	
	USART_BRR =0x00000341 ;
	
	/* USART_CR2 */
	USART_CR2 = 0x00000000 ;
#if 0
    /*Clear bit LIN mode enable*/
	CLR_BIT(USART_CR2,LINEN_BIT) ;
	/* Stop bits 00: 1 Stop bit */
	CLR(USART_CR2,STOP1_BIT) ;
	CLR(USART_CR2,STOP0_BIT) ;
	/*Clear bit Clock enable*/
	CLR(USART_CR2,CLKEN_BIT) ;
	/*Clear bit Clock polarity*/
	CLR(USART_CR2,CPOL_BIT) ;
	/*Clear bit Clock phase*/
	CLR(USART_CR2,CPHA_BIT) ;
	/*Clear bit Last bit clock pulse */
	CLR(USART_CR2,LBCL_BIT) ;
	/*Clear bit LIN break detection interrupt enable */
	CLR(USART_CR2,LBDIE_BIT) ;
	/*Clear bit lin break detection length */
	CLR(USART_CR2,LBDL_BIT) ;
	/*Address of the USART node 00000 */
	CLR(USART_CR2,ADD3_BIT) ;
	CLR(USART_CR2,ADD2_BIT) ;
	CLR(USART_CR2,ADD1_BIT) ;
	CLR(USART_CR2,ADD0_BIT) ;
#endif	
	
	/* USART_CR1 */
	USART_CR1 = 0x0000200C ;

#if 0	
	/*Set bit USART enable*/
	SET_BIT(USART_CR1,UE_BIT) ;
	/*Clear bit Word length (1 Start bit, 8 Data bits, n Stop bit)*/
	CLR_BIT(USART_CR1,M_BIT) ;
	/*Clear bit Wakeup method (Idle Line)*/
	CLR_BIT(USART_CR1,WAKE_BIT) ;
	/*Clear bit Parity control enable (NO parity)*/
	CLR_BIT(USART_CR1,PCE_BIT) ;
	/*Clear bit Parity selection (NO parity)*/
	CLR_BIT(USART_CR1,PS_BIT) ;
	/*Clear bit PE interrupt enable (Interrupt is inhibited) */
	CLR_BIT(USART_CR1,PEIE_BIT) ;
	/*Clear bit TXE interrupt enable (Interrupt is inhibited) */
	CLR_BIT(USART_CR1,TXEIE_BIT) ;
	/*Clear bit Transmission complete interrupt enable (Interrupt is inhibited) */
	CLR_BIT(USART_CR1,TCIE_BIT) ;
	/*Clear bit RXNE interrupt enable (Interrupt is inhibited) */
	CLR_BIT(USART_CR1,RXNEIE_BIT) ;
	/*Clear bit IDLE interrupt enable (Interrupt is inhibited) */
	CLR_BIT(USART_CR1,IDLEIE_BIT) ;
	/*Set bit Transmitter enable (Transmitter is enabled) */
	SET_BIT(USART_CR1,TE_BIT) ;
	/*Set bit Receiver enable (Receiver is enabled and begins searching for a start bit) */
	SET_BIT(USART_CR1,RE_BIT) ;
	/*Clear bit Receiver wakeup (Receiver in active mode) */
	CLR_BIT(USART_CR1,RWU_BIT) ;
	/*Clear bit Send break (No break character is transmitted) */
	CLR_BIT(USART_CR1,SBK_BIT) ;
#endif 
	/* USART_GTPR */ 
	USART_GTPR = 0x00000000 ;
}

void MUSART_void_sendByte(u8 copy_u8Byte)
{
	while(GET_BIT(USART_SR,TXE_BIT)== 0) ;
	
	USART_DR = copy_u8Byte ;
}


void MUSART_void_recieveByte(u8 *copy_u8Byte)
{
	while(GET_BIT(USART_SR,RXNE_BIT)== 0) ;
	*copy_u8Byte = USART_DR ;
}

void MUSART_void_sendString(const u8 *str)
{
	u8 i = 0 ;
	
	while(str[i] != '\0')
	{
		MUSART_void_sendByte(str[i]) ;
		i++ ;
	}
}

void MUSART_void_receiveString(u8 *str)
{
	u8 i = 0 ;
	
	MUSART_void_recieveByte(&str[i]) ;
	
	while(str[i] != '#')
	{
		i++ ;
		MUSART_void_recieveByte(&str[i]) ;
	}

	str[i] = '\0' ;
}
