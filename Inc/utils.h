/*
 * utils.h
 *
 *  Created on: Mar 5, 2026
 *      Author: Rubin Khadka
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "stdint.h"

// Function prototypes for string conversion utilities
void IntToTwoDigits(uint8_t num, char* str);
void TemperatureToString(float temp, char* str);
void FormatTimeString(uint8_t hour, uint8_t minutes, uint8_t seconds, char* buffer);
void FormatDateString(uint8_t day, uint8_t month, uint8_t year, char* buffer);

#endif /* UTILS_H_ */
