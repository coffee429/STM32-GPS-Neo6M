/*
 * ST47_Neo6M.h
 *
 *  Created on: Apr 24, 2021
 *      Author: Vo Son Tung HUST
 */

#ifndef INC_ST47_NEO6M_H_
#define INC_ST47_NEO6M_H_

#include "main.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define neo huart1
#define debug huart2
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

typedef struct
{
	/* Header */

	/* UTC Time */
	char time[10];

	/* Location */
	char* latitude_str;
	float latitude;
	char*  ns_indicator;
	char* longtitude_str;
	float longtitude;
	char*  ew_indicator;

}GPGGA_Struct;

typedef struct
{
	uint32_t process_time;
	uint8_t rx;
	uint8_t index;
	uint8_t buffer[40];
	bool flag;

	GPGGA_Struct gpgga;

}GPS_Struct;

void GPS_Init();
void GPS_Callback();
void GPS_ProcessData();
double Convert(float degMin);
double GPS_GetLatitude();
double GPS_GetLongtitude();

#endif /* INC_ST47_NEO6M_H_ */
