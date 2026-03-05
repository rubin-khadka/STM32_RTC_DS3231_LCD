/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rubin Khadka
 * @brief          : STM32 RTC LCD Project main file
 ******************************************************************************
 */

#include "stm32f103xb.h"
#include "i2c1.h"

int main(void)
{
  // Initialize peripheral modules
  I2C1_Init();

  while(1)
  {

  }
}
