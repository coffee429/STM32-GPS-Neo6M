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
	/* UTC Time */
	uint8_t utc_hour;
	uint8_t utc_min;
	uint8_t utc_sec;
	uint16_t utc_microsec;

	/* Location */
	float latitude_raw;
	double latitude;
	char  ns_indicator;
	float longtitude_raw;
	double longtitude;
	char  ew_indicator;

	/* Other */
	char gps_quality_indicator;
	uint8_t num_of_satellites;
	float	hdop;
	float	msl_altitude;
	char	msl_units;
	float	geoid_separation;
	char	geoid_units;

	uint16_t	age_of_diffCorr;
	char		diff_ref_station_id[4];
	char		checksum[2];
}GPGGA_Struct;

typedef struct
{
	uint32_t process_time;
	uint8_t rx_tmp;
	uint8_t rx_index;
	uint8_t rx_buffer[512];
	bool flag;

	GPGGA_Struct gpgga;

}GPS_Struct;

void GPS_Init();
void GPS_Callback();
void GPS_GetData();
double Convert(float degMin);
double GPS_GetLatitude();
double GPS_GetLongtitude();

#endif /* INC_ST47_NEO6M_H_ */
