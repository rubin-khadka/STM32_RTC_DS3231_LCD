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
#include "utils.h"

int main(void)
{
  DS3231_Time_t current_time;
  float temperature;
  char buffer[17];

  // Initialize peripheral modules
  TIMER2_Init();
  I2C1_Init();
  LCD_Init();
  DS3231_Init();

  // Initialize DS3231
  if(DS3231_Init() == DS3231_OK)
  {
    LCD_SendString("INITIALIZE. . .");
    LCD_SetCursor(1, 0);
    LCD_SendString("DS3231 OK");
  }
  else
  {
    LCD_SendString("DS3231 Error");
  }

  TIMER2_Delay_ms(2000);

  // Set initial time
  current_time.seconds = 0;
  current_time.minutes = 32;
  current_time.hour = 21;
  current_time.dayofweek = 5;
  current_time.dayofmonth = 6;
  current_time.month = 3;
  current_time.year = 26;      // 2026
  DS3231_SetTime(&current_time);

  while(1)
  {
    // Get current time
    if(DS3231_GetTime(&current_time) == DS3231_OK)
    {
      // Format and display time on LCD
      FormatTimeString(current_time.hour, current_time.minutes, current_time.seconds, buffer);
      LCD_SetCursor(0, 0);
      LCD_SendString(buffer);

      LCD_SendString("  ");

      // Format and display date
      FormatDateString(current_time.dayofmonth, current_time.month, current_time.year, buffer);
      LCD_SetCursor(1, 0);
      LCD_SendString(buffer);
    }

    // Get and display temperature
    temperature = DS3231_GetTemperature();
    TemperatureToString(temperature, buffer);
    LCD_SetCursor(0, 9);
    LCD_SendString("T:");
    LCD_SendString(buffer);

    TIMER2_Delay_ms(1000);
  }
}
