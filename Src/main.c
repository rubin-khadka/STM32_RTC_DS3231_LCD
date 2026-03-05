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
#include "stdio.h"
#include "string.h"

int main(void)
{
  DS3231_Time_t current_time;
  float temperature;

  // Initialize peripheral modules
  TIMER2_Init();
  I2C1_Init();
  LCD_Init();
  DS3231_Init();

  // Initialize DS3231
  if(DS3231_Init() == DS3231_OK)
  {
    LCD_SendString("DS3231 OK");
  }
  else
  {
    LCD_SendString("DS3231 Error");
  }

  TIMER2_Delay_ms(2000);

//  // Set initial time
//  current_time.seconds = 0;
//  current_time.minutes = 12;
//  current_time.hour = 12;
//  current_time.dayofweek = 4;  // Friday
//  current_time.dayofmonth = 5;
//  current_time.month = 3;
//  current_time.year = 26;      // 2026
//  DS3231_SetTime(&current_time);

  while(1)
  {
    char buffer[17];
    // Get current time
    if(DS3231_GetTime(&current_time) == DS3231_OK)
    {
      // Display time on LCD
      sprintf(buffer, "%02d:%02d:%02d", current_time.hour, current_time.minutes, current_time.seconds);
      LCD_SetCursor(0, 0);
      LCD_SendString(buffer);
      LCD_SendString(" ");
      LCD_SendString(" ");

      sprintf(buffer, "%02d/%02d/20%02d", current_time.dayofmonth, current_time.month, current_time.year);
      LCD_SetCursor(1, 0);
      LCD_SendString(buffer);
    }

    // Get temperature
    temperature = DS3231_GetTemperature();
    sprintf(buffer, "T:%.1fC", temperature);
    LCD_SetCursor(0, 9);
    LCD_SendString(buffer);

    TIMER2_Delay_ms(1000);
  }
}
