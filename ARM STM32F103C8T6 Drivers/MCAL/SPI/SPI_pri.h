/*
 * SPI_pri.h
 *
 *  Created on: Feb 21, 2023
 *      Author: Ahmed Tarek
 */

#ifndef SPI_SPI_PRI_H_
#define SPI_SPI_PRI_H_

#define		SPI_BASE_ADD	(0x40013000)

#define		SPI_CR1			*((volatile u32 *)(SPI_BASE_ADD+0x00))
#define		SPI_CR2			*((volatile u32 *)(SPI_BASE_ADD+0x04))
#define		SPI_SR			*((volatile u32 *)(SPI_BASE_ADD+0x08))
#define		SPI_DR			*((volatile u32 *)(SPI_BASE_ADD+0x0C))
#define		SPI_CRCPR		*((volatile u32 *)(SPI_BASE_ADD+0x10))
#define		SPI_RXCRCR		*((volatile u32 *)(SPI_BASE_ADD+0x14))
#define		SPI_TXCRCR		*((volatile u32 *)(SPI_BASE_ADD+0x18))
#define		SPI_I2SCFGR		*((volatile u32 *)(SPI_BASE_ADD+0x1C))
#define		SPI_I2SPR		*((volatile u32 *)(SPI_BASE_ADD+0x20))



#endif /* SPI_SPI_PRI_H_ */
