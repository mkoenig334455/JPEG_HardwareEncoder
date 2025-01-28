/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    jpeg.h
  * @brief   This file contains all the function prototypes for
  *          the jpeg.c file
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
#ifndef __JPEG_H__
#define __JPEG_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern JPEG_HandleTypeDef hjpeg;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_JPEG_Init(void);

/* USER CODE BEGIN Prototypes */
#define JPEG_CHROMA_SAMPLING     JPEG_420_SUBSAMPLING   /* Select Chroma Sampling: JPEG_420_SUBSAMPLING, JPEG_422_SUBSAMPLING, JPEG_444_SUBSAMPLING   */
#define JPEG_COLOR_SPACE         JPEG_YCBCR_COLORSPACE  /* Select Color Space: JPEG_YCBCR_COLORSPACE, JPEG_GRAYSCALE_COLORSPACE, JPEG_CMYK_COLORSPACE */
#define JPEG_IMAGE_QUALITY       75                     /* Set Image Quality for Jpeg Encoding */
#define MAX_INPUT_WIDTH          800                    /* Set the Maximum of BMP images Width to be tested */
#define MAX_INPUT_LINES          16                     /* Set Input buffer lines to 16 for YCbCr420, and 8 for YCbCr422 and YCbCr444 (to save RAM space) */
#define DMABUFFER_AREA      0x24062000
#define DMABUFFER_AREA_SIZE MPU_REGION_SIZE_64KB

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __JPEG_H__ */

