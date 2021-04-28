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
#include <stdlib.h>
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
	float latitude;
	char*  ns_indicator;
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
float Convert(float degMin);
float GPS_GetLatitude();
float GPS_GetLongtitude();

#endif /* INC_ST47_NEO6M_H_ */
