/*
 * ST47_Neo6M.c
 *
 *  Created on: Apr 24, 2021
 *      Author: Vo Son Tung HUST
 */


#include "ST47_Neo6M.h"
GPS_Struct gps;

double Convert(float degMin)
{
	double min = 0.0;
	double decDeg = 0.0;

	//get the minutes, fmod() requires double
	min = fmod((double)degMin, 100.0);

	//rebuild coordinates in decimal degrees
	degMin = (int) ( degMin / 100 );
	decDeg = degMin + ( min / 60 );

	return decDeg;
}

void GPS_Init()
{
	gps.index = 0;
	HAL_UART_Receive_IT(&neo, &gps.rx, 1);
}

void GPS_Callback()
{
	if(gps.rx == '\n')
	{
		gps.flag = true;
		gps.index = 0;
	}
	else gps.buffer[gps.index ++] = gps.rx;
	HAL_UART_Receive_IT(&neo, &gps.rx, 1);
}

//void GPS_GetData()
//{
//	if(gps.flag == true)
//	{
//		char* response = strstr((char*)gps.buffer, "$GPGGA");
//		if(response != NULL)
//		{
//			memset(&gps.gpgga, 0, sizeof(gps.gpgga));
//			sscanf(response,"$GPGGA, %2hhd%2hhd%2hhd.%3hd,%f,%c,%f,%c,%hhd,%hhd,%f,%f,%c,%hd,%s,*%2s\r\n", &gps.gpgga.utc_hour, &gps.gpgga.utc_min, &gps.gpgga.utc_sec, &gps.gpgga.utc_microsec, &gps.gpgga.latitude_raw, &gps.gpgga.ns_indicator, &gps.gpgga.longtitude_raw, &gps.gpgga.ew_indicator, &gps.gpgga.gps_quality_indicator, &gps.gpgga.num_of_satellites, &gps.gpgga.hdop, &gps.gpgga.msl_altitude, &gps.gpgga.msl_units, &gps.gpgga.age_of_diffCorr, gps.gpgga.diff_ref_station_id, gps.gpgga.checksum); // @suppress("Float formatting support")
//			gps.gpgga.latitude = Convert(gps.gpgga.latitude_raw);
//			gps.gpgga.longtitude = Convert(gps.gpgga.longtitude_raw);
//		}
//		HAL_UART_Transmit(&debug, gps.buffer, sizeof(gps.buffer), 2000);
//		gps.flag = false;
//	}
//}

void GPS_ProcessData()
{
	if(gps.flag == true)
	{
		char* response = strstr((char*)gps.buffer, "$GPGGA");
		if(response != NULL)
		{
			char* token = strtok(response, ",");
			strcpy(gps.gpgga.time, strtok(NULL, ","));
			gps.gpgga.latitude = atof(strtok(NULL, ","));
			gps.gpgga.ns_indicator = strtok(NULL, ",");
			gps.gpgga.longtitude = atof(strtok(NULL, ","));
			gps.gpgga.ew_indicator = strtok(NULL, ",");
		}
		HAL_UART_Transmit(&debug, gps.buffer, sizeof(gps.buffer), 2000);
		gps.flag = false;
	}
}

double GPS_GetLatitude()
{
	return gps.gpgga.latitude;
}

double GPS_GetLongtitude()
{
	return gps.gpgga.longtitude;
}
