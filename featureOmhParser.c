#include "featureOmhParser.h"

int isRealisticallyOMH(OMHFile *header){
	if (header->magicMarker1 != 0xFA) return 1;
	if (header->magicMarker2 != 0xF0) return 2;
	if (header->fileNumber1 != header->fileNumber2) return 10;
	return 0;
}
inline unsigned int getDistanceMeters(OMHFile *header){
	return header->distance;
}
inline float getDistanceKilometers(OMHFile *header){
	return ((float)(header->distance))/100;
}
inline float getSpeedMetersPerSecond(OMHFile *header){
	return ((float)(header->speed))/100/3.6f;
}
inline float getSpeedKilometersPerHour(OMHFile *header){
	return ((float)(header->speed))/100;
}
inline unsigned int getKilocaloriesBurned(OMHFile *header){
	return header->energy;
}

struct tm getStartTime(OMHFile *header){
	struct tm startTime;
	startTime.tm_year = 2000 + header->year - 1900;
	startTime.tm_mon  = header->month - 1;
	startTime.tm_mday = header->day;
	startTime.tm_hour = header->hour;
	startTime.tm_min  = header->minute;
	startTime.tm_sec  = header->second;
	return startTime;
}


struct tm getRunTime(OMHFile *header){
	struct tm runTime;
	runTime.tm_yday = header->duration / (60*60*24) - 1;
	runTime.tm_hour = header->duration / (60*60);
	runTime.tm_min  = header->duration / 60;
	runTime.tm_sec  = header->duration % 60;
	return runTime;
}