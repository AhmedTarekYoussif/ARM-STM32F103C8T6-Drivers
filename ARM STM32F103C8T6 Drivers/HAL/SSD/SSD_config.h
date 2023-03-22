/*
 * SSD_config.h
 *
 *  Created on: Feb 1, 2023
 *  Author: Ahmed Tarek Youssef
 */

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_

/*
 * Please Choose :
 * SSD_LED_A_PORT : PORTA_ID...PORTD_ID
 * SSD_LED_A_PIN  : PIN0_ID....PIN7_ID
 */

#define SSD_DISPLAY_TIME   250

#define SSD_LED_A_PORT    PORTA
#define SSD_LED_A_PIN     PIN11

#define SSD_LED_B_PORT    PORTA
#define SSD_LED_B_PIN     PIN8

#define SSD_LED_C_PORT    PORTB
#define SSD_LED_C_PIN     PIN15

#define SSD_LED_D_PORT    PORTB
#define SSD_LED_D_PIN     PIN14

#define SSD_LED_E_PORT    PORTB
#define SSD_LED_E_PIN     PIN13

#define SSD_LED_F_PORT    PORTB
#define SSD_LED_F_PIN     PIN12

#define SSD_LED_G_PORT    PORTA
#define SSD_LED_G_PIN     PIN12

#define SSD_LED_DOT_PORT   PORTA
#define SSD_LED_DOT_PIN    PIN15


#define SSD_DIG_1_EN_PORT    PORTB
#define SSD_DIG_1_EN_PIN     PIN9

#define SSD_DIG_2_EN_PORT    PORTB
#define SSD_DIG_2_EN_PIN     PIN8

#define SSD_DIG_3_EN_PORT    PORTB
#define SSD_DIG_3_EN_PIN     PIN3

#endif /* HAL_SSD_SSD_CONFIG_H_ */
