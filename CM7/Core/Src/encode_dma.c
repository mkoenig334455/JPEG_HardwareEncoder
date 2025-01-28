#include "main.h"
#include "jpeg_utils.h"
#include "encode_dma.h"


// variables used for dma mode
uint32_t YCBCR_Size;
uint32_t YCBCR_Index;
uint32_t YCBCR_Packets;
uint32_t YCBCR_Packet_Size;
uint8_t *YCBCR_IMG;
uint8_t Encoded_Flag;
uint8_t DMA_Mode;
//
uint32_t JPEG_Size;
uint32_t jpeg_encode_processing_end;
uint32_t Jpeg_HWEncodingEnd;

HAL_StatusTypeDef sts1,sts2,sts3;

uint32_t JPEG_Encode_HW(JPEG_HandleTypeDef *hjpeg,
                        uint8_t *img,       // pointer input rgb map
                        uint32_t img_x,     // image width
                        uint32_t img_y,     // image hight
                        uint8_t img_bytpp,  // bytes per pixel
                        uint8_t quality,    // out jpeg quality
                        uint8_t *ycbcr_tmp, // temperory buffer for ycbcr conversion, must be sizes appropriately
                        uint8_t *jpg_out)   // where out jpeg is stored, must be sizes appropriately
{
  JPEG_ConfTypeDef Conf;
  JPEG_RGBToYCbCr_Convert_Function pRGBToYCbCr_Convert_Function;

  uint32_t ycbcr_mcu = 0;
  uint32_t ycbcr_size = 0;
  JPEG_Size = 0;
  DMA_Mode = 0;
  Encoded_Flag = 0;

  Conf.ImageWidth = img_x;
  Conf.ImageHeight = img_y;
  Conf.ChromaSubsampling = JPEG_420_SUBSAMPLING;
  Conf.ColorSpace = JPEG_YCBCR_COLORSPACE;
  Conf.ImageQuality = quality;

  X3_Pin_On;
  // get the numbers of mcus and appropriate function to rgb to ycbcr
  sts1 = JPEG_GetEncodeColorConvertFunc(&Conf, &pRGBToYCbCr_Convert_Function, &ycbcr_mcu);

  X4_Pin_On;
  // convert rgb to ycbcr mcu in one go
  pRGBToYCbCr_Convert_Function(img, ycbcr_tmp, 0, (img_x * img_y * img_bytpp), &ycbcr_size);//~19ms

  X5_Pin_On;
  sts2 = HAL_JPEG_ConfigEncoding(hjpeg, &Conf);

  X6_Pin_On;
  // convert ycbcr mcus to jpeg in one go
  sts3 = HAL_JPEG_Encode(hjpeg, ycbcr_tmp, ycbcr_size, jpg_out, (img_x * img_y * img_bytpp), HAL_MAX_DELAY);//~9ms

  // JPEG_Size is updated in HAL_JPEG_DataReadyCallback
  return JPEG_Size;
}

























// poll encoding status if using dma mode
uint8_t JPEG_Get_Status(uint32_t *size)
{
  uint8_t tmp = Encoded_Flag;
  *size = JPEG_Size;
  Encoded_Flag = 0;
  return tmp;
}
//////////////////////////////////////// callbacks and ISRS ////////////////////////////////////////////
/**
  * @brief JPEG Get Data callback
  * @param hjpeg: JPEG handle pointer
  * @param NbEncodedData: Number of encoded (consummed) bytes from input buffer
  * @retval None
  */
void HAL_JPEG_GetDataCallback(JPEG_HandleTypeDef *hjpeg, uint32_t NbEncodedData)
{
  if (DMA_Mode)
  {
    if (YCBCR_Index == YCBCR_Packets)
    {
      YCBCR_Packet_Size = YCBCR_Size % YCBCR_Packet_Size;
    }



    // feed ycbcr mcus to jpeg in blocks of YCBCR_Packet_Size
    HAL_JPEG_ConfigInputBuffer(hjpeg, YCBCR_IMG, YCBCR_Packet_Size);
    YCBCR_Index++;
    YCBCR_IMG += YCBCR_Packet_Size;

    if (YCBCR_Index > YCBCR_Packets)
    {
      YCBCR_Index = 0x00;
      //    got it working
      //
      //    I had to put
      //
      //     SCB_CleanInvalidateDCache();
      //
      //     SCB_InvalidateICache();
      //
      //    before dma call and removing this line "HAL_JPEG_ConfigInputBuffer(hjpeg, YCBCR_IMG, 4);" from HAL_JPEG_GetDataCallback
      // if HAL_JPEG_Pause or HAL_JPEG_ConfigInputBuffer with zero length here then HAL_JPEG_DataReadyCallbackn will not be called
      HAL_JPEG_ConfigInputBuffer(hjpeg, YCBCR_IMG, 4);
    }
  }
}

/**
  * @brief JPEG Data Ready callback
  * @param hjpeg: JPEG handle pointer
  * @param pDataOut: pointer to the output data buffer
  * @param OutDataLength: length of output buffer in bytes
  * @retval None
  */
void HAL_JPEG_DataReadyCallback(JPEG_HandleTypeDef *hjpeg, uint8_t *pDataOut, uint32_t OutDataLength)
{
  JPEG_Size = OutDataLength;
}

/**
  * @brief  JPEG Error callback
  * @param hjpeg: JPEG handle pointer
  * @retval None
  */
void HAL_JPEG_ErrorCallback(JPEG_HandleTypeDef *hjpeg)
{
  while (1)
  {
  }
}

/*
  * @brief JPEG Decode complete callback
  * @param hjpeg: JPEG handle pointer
  * @retval None
  */
void HAL_JPEG_EncodeCpltCallback(JPEG_HandleTypeDef *hjpeg)
{
  Encoded_Flag = 1;
  Jpeg_HWEncodingEnd = 1;
}
