/**
  ******************************************************************************
  * @file    JPEG/JPEG_EncodingFromXSPI_DMA/Appli/Inc/encode_dma.h
  * @author  MCD Application Team
  * @brief   Header for encode_dma.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ENCODE_DMA_H
#define __ENCODE_DMA_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

// variables used for dma mode
extern uint32_t YCBCR_Size;
extern uint32_t YCBCR_Index;
extern uint32_t YCBCR_Packets;
extern uint32_t YCBCR_Packet_Size;
extern uint8_t *YCBCR_IMG;
extern uint8_t Encoded_Flag;
extern uint8_t DMA_Mode;

extern uint32_t JPEG_Size;
extern uint32_t jpeg_encode_processing_end;
extern uint32_t Jpeg_HWEncodingEnd;

/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern uint32_t JPEG_EncodeOutputHandler(JPEG_HandleTypeDef *hjpeg);
extern void JPEG_EncodeInputHandler(JPEG_HandleTypeDef *hjpeg);

extern uint32_t JPEG_Encode_HW(JPEG_HandleTypeDef *hjpeg,
                        uint8_t *img,       // pointer input rgb map
                        uint32_t img_x,     // image width
                        uint32_t img_y,     // image hight
                        uint8_t img_bytpp,  // bytes per pixel
                        uint8_t quality,    // out jpeg quality
                        uint8_t *ycbcr_tmp, // temperory buffer for ycbcr conversion, must be sizes appropriately
                        uint8_t *jpg_out);   // where out jpeg is stored, must be sizes appropriately

extern void JPEG_Encode_HW_DMA(JPEG_HandleTypeDef *hjpeg,
                        uint8_t *img,       // pointer input rgb map
                        uint32_t img_x,     // image width
                        uint32_t img_y,     // image hight
                        uint8_t img_bytpp,  // bytes per pixel
                        uint8_t quality,    // out jpeg quality
                        uint8_t *ycbcr_tmp, // temperory buffer for ycbcr conversion, must be sizes appropriately
                        uint8_t *jpg_out);   // where out jpeg is stored, must be sizes appropriately


#endif /* __ENCODE_DMA_H */

