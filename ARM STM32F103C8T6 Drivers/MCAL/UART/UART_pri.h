/*
 * UART_pri.h
 *
 *  Created on: Feb 21, 2023
 *      Author: Ahmed Tarek
 */

#ifndef UART_UART_PRI_H_
#define UART_UART_PRI_H_

#define		USART1_BASE_ADD	(0x40013800)

#define		USART_SR		*((volatile u32 *)(USART1_BASE_ADD+0x00))
#define		USART_DR		*((volatile u32 *)(USART1_BASE_ADD+0x04))
#define		USART_BRR		*((volatile u32 *)(USART1_BASE_ADD+0x08))
#define		USART_CR1		*((volatile u32 *)(USART1_BASE_ADD+0x0C))
#define		USART_CR2		*((volatile u32 *)(USART1_BASE_ADD+0x10))
#define		USART_CR3		*((volatile u32 *)(USART1_BASE_ADD+0x14))
#define		USART_GTPR		*((volatile u32 *)(USART1_BASE_ADD+0x18))

/* USART_SR register flags */

#define TXE_BIT		7
#define TC_BIT     	6
#define RXNE_BIT    5

/* USART_CR1 */
#define UE_BIT		13	   /*USART enable*/
#define M_BIT		12     /*Word length*/
#define WAKE_BIT	11     /*Wakeup method*/
#define PCE_BIT		10     /*Parity control enable*/
#define PS_BIT		9      /*Parity selection*/
#define PEIE_BIT	8      /*PE interrupt enable*/
#define TXEIE_BIT	7      /*TXE interrupt enable*/
#define TCIE_BIT	6      /*Transmission complete interrupt enable*/
#define RXNEIE_BIT	5      /*RXNE interrupt enable*/
#define IDLEIE_BIT	4      /*IDLE interrupt enable*/
#define TE_BIT		3      /*Transmitter enable*/
#define RE_BIT		2      /*Receiver enable*/
#define RWU_BIT		1      /*Receiver wakeup*/
#define SBK_BIT		0      /*Send break*/

/* USART_CR2 */

#define LINEN_BIT	14	   /*LIN mode enable*/
#define STOP1_BIT	13     /*STOP bits*/
#define STOP0_BIT	12     /*STOP bits*/
#define CLKEN_BIT	11	   /*Clock enable*/
#define CPOL_BIT	10     /*Clock polarity*/
#define CPHA_BIT	9      /*Clock phase*/
#define LBCL_BIT	8      /*Last bit clock pulse*/
#define LBDIE_BIT	6      /*LIN break detection interrupt enable*/
#define LBDL_BIT	5      /*lin break detection length*/
#define ADD3_BIT	3      /*Address of the USART node*/
#define ADD2_BIT	2      /*Address of the USART node*/
#define ADD1_BIT	1      /*Address of the USART node*/
#define ADD0_BIT	0      /*Address of the USART node*/



#endif /* UART_UART_PRI_H_ */
