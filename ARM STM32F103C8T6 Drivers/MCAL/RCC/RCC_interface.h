#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H


#define		RCC_AHB			0
#define		RCC_APB1		1
#define		RCC_APB2		2

void	MRCC_voidSysClkInit(void);
void	MRCC_voidEnablePerClk(u8 PerBus,u8 PerNum);
void	MRCC_voidDisablePerClk(u8 PerBus,u8 PerNum);


#endif