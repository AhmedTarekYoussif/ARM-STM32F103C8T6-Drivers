/*
 * STK_init.h
 *
 *  Created on: Mar 6, 2023
 *      Author: mohamed
 */

#ifndef STK_STK_INIT_H_
#define STK_STK_INIT_H_

void	STK_voidInit(void);
void	STK_voidBusyWait(u32 Ticks);
void	STK_voidSetIntervalSingle(u32 Ticks,void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32 Ticks,void (*Pf)(void));
void	STK_voidStopInterval(void);
u32		STK_u32GetElapsedTime(void);
u32		STK_u32GetRemainingTime(void);

#endif /* STK_STK_INIT_H_ */
