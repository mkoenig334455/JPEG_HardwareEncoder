/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
//#define 16FARBENBMP_HEIGHT 20
//#define 16FARBENBMP_WIDTH 20
#define BYTESPERPIXEL	3

#define IMG_WIDTH 320
#define IMG_HEIGHT 240
#define RGB_IMAGE_SIZE IMG_HEIGHT*IMG_WIDTH*BYTESPERPIXEL

extern const uint8_t Image_RGB888[RGB_IMAGE_SIZE];
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FPGA_CS_Pin GPIO_PIN_1
#define FPGA_CS_GPIO_Port GPIOD
#define EXT_ON_Pin GPIO_PIN_7
#define EXT_ON_GPIO_Port GPIOB
#define FPGA_DATA_CS_Pin GPIO_PIN_14
#define FPGA_DATA_CS_GPIO_Port GPIOH
#define CLK_OUT_Pin GPIO_PIN_8
#define CLK_OUT_GPIO_Port GPIOA
#define FPGA_RESET_Pin GPIO_PIN_12
#define FPGA_RESET_GPIO_Port GPIOA
#define EnableLine_Pin GPIO_PIN_10
#define EnableLine_GPIO_Port GPIOC
#define TASTE5_Pin GPIO_PIN_8
#define TASTE5_GPIO_Port GPIOC
#define TASTE4_Pin GPIO_PIN_7
#define TASTE4_GPIO_Port GPIOC
#define LAN_CLK_Pin GPIO_PIN_9
#define LAN_CLK_GPIO_Port GPIOC
#define TASTE3_Pin GPIO_PIN_14
#define TASTE3_GPIO_Port GPIOD
#define TASTE1_Pin GPIO_PIN_13
#define TASTE1_GPIO_Port GPIOD
#define TASTE2_Pin GPIO_PIN_12
#define TASTE2_GPIO_Port GPIOD
#define X7_Pin GPIO_PIN_14
#define X7_GPIO_Port GPIOE
#define X1_Pin GPIO_PIN_8
#define X1_GPIO_Port GPIOE
#define USB_RESET_Pin GPIO_PIN_12
#define USB_RESET_GPIO_Port GPIOH
#define X5_Pin GPIO_PIN_12
#define X5_GPIO_Port GPIOE
#define X6_Pin GPIO_PIN_13
#define X6_GPIO_Port GPIOE
#define X8_Pin GPIO_PIN_15
#define X8_GPIO_Port GPIOE
#define X3_Pin GPIO_PIN_10
#define X3_GPIO_Port GPIOE
#define X2_Pin GPIO_PIN_9
#define X2_GPIO_Port GPIOE
#define X4_Pin GPIO_PIN_11
#define X4_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

#define X1_Pin_Toggle 	HAL_GPIO_TogglePin(X1_GPIO_Port, X1_Pin)
#define X2_Pin_Toggle 	HAL_GPIO_TogglePin(X2_GPIO_Port, X2_Pin)
#define X3_Pin_Toggle 	HAL_GPIO_TogglePin(X3_GPIO_Port, X3_Pin)
#define X4_Pin_Toggle 	HAL_GPIO_TogglePin(X4_GPIO_Port, X4_Pin)
#define X5_Pin_Toggle 	HAL_GPIO_TogglePin(X5_GPIO_Port, X5_Pin)
#define X6_Pin_Toggle 	HAL_GPIO_TogglePin(X6_GPIO_Port, X6_Pin)
#define X7_Pin_Toggle 	HAL_GPIO_TogglePin(X7_GPIO_Port, X7_Pin)
#define X8_Pin_Toggle 	HAL_GPIO_TogglePin(X8_GPIO_Port, X8_Pin)

#define X1_Pin_On 		HAL_GPIO_WritePin(X1_GPIO_Port, X1_Pin, GPIO_PIN_SET)
#define X2_Pin_On 		HAL_GPIO_WritePin(X2_GPIO_Port, X2_Pin, GPIO_PIN_SET)
#define X3_Pin_On 		HAL_GPIO_WritePin(X3_GPIO_Port, X3_Pin, GPIO_PIN_SET)
#define X4_Pin_On 		HAL_GPIO_WritePin(X4_GPIO_Port, X4_Pin, GPIO_PIN_SET)
#define X5_Pin_On 		HAL_GPIO_WritePin(X5_GPIO_Port, X5_Pin, GPIO_PIN_SET)
#define X6_Pin_On 		HAL_GPIO_WritePin(X6_GPIO_Port, X6_Pin, GPIO_PIN_SET)
#define X7_Pin_On 		HAL_GPIO_WritePin(X7_GPIO_Port, X7_Pin, GPIO_PIN_SET)
#define X8_Pin_On 		HAL_GPIO_WritePin(X8_GPIO_Port, X8_Pin, GPIO_PIN_SET)

#define X1_Pin_Off 		HAL_GPIO_WritePin(X1_GPIO_Port, X1_Pin, GPIO_PIN_RESET)
#define X2_Pin_Off 		HAL_GPIO_WritePin(X2_GPIO_Port, X2_Pin, GPIO_PIN_RESET)
#define X3_Pin_Off 		HAL_GPIO_WritePin(X3_GPIO_Port, X3_Pin, GPIO_PIN_RESET)
#define X4_Pin_Off 		HAL_GPIO_WritePin(X4_GPIO_Port, X4_Pin, GPIO_PIN_RESET)
#define X5_Pin_Off 		HAL_GPIO_WritePin(X5_GPIO_Port, X5_Pin, GPIO_PIN_RESET)
#define X6_Pin_Off 		HAL_GPIO_WritePin(X6_GPIO_Port, X6_Pin, GPIO_PIN_RESET)
#define X7_Pin_Off 		HAL_GPIO_WritePin(X7_GPIO_Port, X7_Pin, GPIO_PIN_RESET)
#define X8_Pin_Off 		HAL_GPIO_WritePin(X8_GPIO_Port, X8_Pin, GPIO_PIN_RESET)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
