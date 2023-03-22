/*
 * UART_int.h
 *
 *  Created on: Feb 21, 2023
 *       Author: Ahmed Tarek
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

void MUSART_void_init(void) ;
void MUSART_void_sendByte(u8 copy_u8Byte) ;
void MUSART_void_recieveByte(u8 *copy_u8Byte) ;
void MUSART_void_sendString(const u8 *str) ;
void MUSART_void_receiveString(u8 *str) ;



#endif /* UART_UART_INT_H_ */
