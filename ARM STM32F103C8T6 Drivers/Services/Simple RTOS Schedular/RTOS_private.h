#ifndef		RTOS_PRIVATE_H
#define		RTOS_PRIVATE_H

typedef	struct
{
	u16 u16_Periodicity;
	u16 u16_FirstDelay ;
	void	(*pf)	(void);
}Task_TCB ;

static void RTOS_voidScheduler(void);

#endif
