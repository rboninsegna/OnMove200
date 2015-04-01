#ifndef ONMOVE200_HEADER_TOOLS
	#define ONMOVE200_HEADER_TOOLS
	
	#include <time.h>
	#include "OM200HeaderFile.h"
	
		
	/** Verify some assumptions intrinsic to the format:
	 * returns 1|2 if first|second magic check fails,
	 *         10 if the two copies of the sequential number differ */
	 int isRealisticallyOMH(OMHFile *header);
	
	/** Returns distance walked. */
	inline unsigned int getDistanceMeters(OMHFile *header);
	inline float getDistanceKilometers(OMHFile *header);
	
	/** Returns average speed. */
	inline float getSpeedMetersPerSecond(OMHFile *header);
	inline float getSpeedKilometersPerHour(OMHFile *header);
	
	/** Returns energy consumed */
	inline unsigned int getKilocaloriesBurned(OMHFile *header);	
	
	/** Returns start time */
	struct tm getStartTime(OMHFile *header);
	
	/** Returns activity duration */
	struct tm getRunTime(OMHFile *header);
	
#endif
	