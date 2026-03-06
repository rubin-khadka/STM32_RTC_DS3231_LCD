/*
 * utils.c
 *
 *  Created on: Mar 5, 2026
 *      Author: Rubin Khadka
 */

#include "utils.h"

// Convert a 2-digit number to string
void IntToTwoDigits(uint8_t num, char* str)
{
    str[0] = '0' + (num / 10);  // Tens digit
    str[1] = '0' + (num % 10);  // Ones digit
    str[2] = '\0';               // Null terminator
}

// Convert temperature to string with 1 decimal place
void TemperatureToString(float temp, char* str)
{
    int8_t int_part = (int8_t)temp;
    uint8_t frac_part = (uint8_t)((temp - int_part) * 10);

    // Handle negative temperatures
    if(int_part < 0)
    {
        str[0] = '-';
        int_part = -int_part;
        IntToTwoDigits(int_part, &str[1]);
        str[3] = '.';
        str[4] = '0' + frac_part;
        str[5] = 'C';
        str[6] = '\0';
    }
    else
    {
        IntToTwoDigits(int_part, str);
        str[2] = '.';
        str[3] = '0' + frac_part;
        str[4] = 'C';
        str[5] = '\0';
    }
}

// Format time string as HH:MM:SS
void FormatTimeString(uint8_t hour, uint8_t minutes, uint8_t seconds, char* buffer)
{
    // Hour
    buffer[0] = '0' + (hour / 10);
    buffer[1] = '0' + (hour % 10);
    buffer[2] = ':';

    // Minutes
    buffer[3] = '0' + (minutes / 10);
    buffer[4] = '0' + (minutes % 10);
    buffer[5] = ':';

    // Seconds
    buffer[6] = '0' + (seconds / 10);
    buffer[7] = '0' + (seconds % 10);
    buffer[8] = '\0';
}

// Format date string as DD/MM/YYYY
void FormatDateString(uint8_t day, uint8_t month, uint8_t year, char* buffer)
{
    // Day
    buffer[0] = '0' + (day / 10);
    buffer[1] = '0' + (day % 10);
    buffer[2] = '/';

    // Month
    buffer[3] = '0' + (month / 10);
    buffer[4] = '0' + (month % 10);
    buffer[5] = '/';

    // Year (20YY)
    buffer[6] = '2';
    buffer[7] = '0';
    buffer[8] = '0' + (year / 10);
    buffer[9] = '0' + (year % 10);
    buffer[10] = '\0';
}
