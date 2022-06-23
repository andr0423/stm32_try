/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.cpp file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */



extern const char mqtt_ip[15];



/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

// need interval 6 sec
//
// SysTic   = 216 000 000 GHz
// prescale 16bit < 65536
// 4 timer ticks per 1 ms
// prescale = 53999
// + divider /2  (?)
// period = 6 * 1000 * 4 /2 = 12000

//  3 sec ->  6000
//  6 sec -> 12000 <-- vkr
// 10 sec -> 20000
// 12 sec -> 24000

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MY_PERIOD 12000
#define MY_VERSION 202206110440
#define MY_PRESCALER 53999
#define OLED_CS_Pin GPIO_PIN_3
#define OLED_CS_GPIO_Port GPIOE
#define USR_BTN_Pin GPIO_PIN_13
#define USR_BTN_GPIO_Port GPIOC
#define USR_BTN_EXTI_IRQn EXTI15_10_IRQn
#define DHT11_1_wire_Pin GPIO_PIN_2
#define DHT11_1_wire_GPIO_Port GPIOF
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define OLED_Res_Pin GPIO_PIN_0
#define OLED_Res_GPIO_Port GPIOG
#define OLED_DC_Pin GPIO_PIN_1
#define OLED_DC_GPIO_Port GPIOG
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define SW0_Pin GPIO_PIN_3
#define SW0_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_7
#define LD2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

//
// My IP configurations
//

#define MY_MQTT_SERVER_IP_ADDRES \
    { '1','9','2', '.', '1','6','8' , '.', '1','0','0' , '.' , '1','0','0' }

#define MY_IP_ADDR_0  192
#define MY_IP_ADDR_1  168
#define MY_IP_ADDR_2  100
#define MY_IP_ADDR_3  200

#define MY_NETMASK_0  255
#define MY_NETMASK_1  255
#define MY_NETMASK_2  255
#define MY_NETMASK_3  0

#define MY_GATEWAY_0  192
#define MY_GATEWAY_1  168
#define MY_GATEWAY_2  100
#define MY_GATEWAY_3  1

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
