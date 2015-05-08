#include "OM200HeaderFile.h"
#include <stdio.h>
int isRealisticallyOMH(OMHFile *header){
	if (header->magicMarker1 != 0xFA) return 1;
	if (header->magicMarker2 != 0xF0) return 2;
	if (header->fileNumber1 != header->fileNumber2) return 6;
	if (header->fileNumber1 != header->fileNumber3) return 7;
	return 0;
}
int wasGpsEnabled(OMHFile *header){
	if (header->gpsOff == 0) return 1;
	else return 0;
}


inline unsigned int getDistanceMeters(OMHFile *header){
	return header->distance;
}
inline float getDistanceKilometers(OMHFile *header){
	return ((float)(header->distance))/1000;
}

inline float getSpeedKilometersPerHour(OMHFile *header){
	return ((float)(header->speed))/100;
}
inline float getMaxSpeedKilometersPerHour(OMHFile *header){
	return ((float)(header->peakSpeed))/100;
}

inline unsigned int getKilocaloriesBurned(OMHFile *header){
	return header->energy;
}

inline unsigned long getDurationSeconds(OMHFile *header){
	return header->duration;
}


inline unsigned int getYear(OMHFile *header){
	return 2000 + header->year;
}
inline unsigned int getMonth(OMHFile *header){
	return header->month;
}
inline unsigned int getDay(OMHFile *header){
	return header->day;
}
inline unsigned int getHour(OMHFile *header){
	return header->hour;
}
inline unsigned int getMinute(OMHFile *header){
	return header->minute;
}

inline unsigned int getHeartRate(OMHFile *header){
	return header->heartRate;
}
inline unsigned int getMaxHeartRate(OMHFile *header){
	return header->peakHeartRate;
}