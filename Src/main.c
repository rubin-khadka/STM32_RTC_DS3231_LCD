/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rubin Khadka
 * @brief          : STM32 RTC LCD Project main file
 ******************************************************************************
 */

#include "stm32f103xb.h"
#include "i2c1.h"
#include "ds3231.h"
#include "timer2.h"
#include "lcd.h"

int main(void)
{
  // Initialize peripheral modules
  TIMER2_Init();
  I2C1_Init();
  LCD_Init();

  while(1)
  {

  }
}
