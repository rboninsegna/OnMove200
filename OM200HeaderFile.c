#include <stdio.h>
#include "OM200HeaderFile.h"

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
