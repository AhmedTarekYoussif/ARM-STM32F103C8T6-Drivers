/*
 * PB_int.h
 *
 *  Created on: Feb 2, 2023
 *  Author: Ahmed Tarek Youssef
 */

#ifndef HAL_PB_PB_INT_H_
#define HAL_PB_PB_INT_H_

/*
 * choose from :
 * PB_ID : 1, 2, 3, 4
 * PB_PORT :  PORTA_ID.....PORTD_ID
 * PB_pin : PIN0_ID....PIN7_ID
 */

#define NOT_PRESSED_ACTIVE_LOW   1
#define PRESSED_ACTIVE_LOW       0

#define NOT_PRESSED_ACTIVE_HIGH  0
#define PRESSED_ACTIVE_HIGH      1


typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}ACTIVE_t;

typedef struct PushButton
{
	u8 PB_ID ;
	u8 PB_port ;
	u8 PB_pin ;
	ACTIVE_t PB_ActiveMode ;
}PB_t ;

void H_PB_Void_init(const PB_t* pcopy_PB) ;

void H_PB_Void_read(const PB_t* ptr, u8* pvalue) ;

#endif /* HAL_PB_PB_INT_H_ */
