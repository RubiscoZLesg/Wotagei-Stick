/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IPS_CS_Pin GPIO_PIN_14
#define IPS_CS_GPIO_Port GPIOC
#define IPS_RES_Pin GPIO_PIN_15
#define IPS_RES_GPIO_Port GPIOC
#define IPS_DC_Pin GPIO_PIN_0
#define IPS_DC_GPIO_Port GPIOA
#define IPS_BLK_Pin GPIO_PIN_3
#define IPS_BLK_GPIO_Port GPIOA
#define SW_DN_Pin GPIO_PIN_4
#define SW_DN_GPIO_Port GPIOA
#define SW_DN_EXTI_IRQn EXTI4_15_IRQn
#define SW_OK_Pin GPIO_PIN_5
#define SW_OK_GPIO_Port GPIOA
#define SW_OK_EXTI_IRQn EXTI4_15_IRQn
#define SW_UP_Pin GPIO_PIN_6
#define SW_UP_GPIO_Port GPIOA
#define SW_UP_EXTI_IRQn EXTI4_15_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
