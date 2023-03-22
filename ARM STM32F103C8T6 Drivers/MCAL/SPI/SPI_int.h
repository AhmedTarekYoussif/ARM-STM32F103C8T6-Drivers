/*
 * SPI_int.h
 *
 *  Created on: Feb 21, 2023
 *       Author: Ahmed Tarek
 */

#ifndef SPI_SPI_INT_H_
#define SPI_SPI_INT_H_


void MSPI_void_initMaster(void); 
void MSPI_void_initSlave(void);

void MSPI_void_sendByte(u8 copy_u8Byte);
void MSPI_void_recieveByte(u8 *copy_u8Byte);

void MSPI_void_sendString(const u8 *str);
void MSPI_void_receiveString(u8 *str);



#endif /* SPI_SPI_INT_H_ */
