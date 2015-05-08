#ifndef ONMOVE200_HEADER_FILE
	#define ONMOVE200_HEADER_FILE
	
	#include <stdint.h>
	
	typedef struct {
	//all numbers are little endian
	//field sizes for all "unknown*" are guesses
	
	//start of file (0x0): general statistics
	uint32_t distance; /** distance in meters */
	uint16_t duration; /** duration in seconds */
	uint16_t speed; /** average speed in decameters per hour = km/h * 100 */
	uint16_t peakSpeed; /** maximum speed in decameters per hour */
	uint16_t energy; /** energy burned in kcal */
	uint8_t heartRate; 
	uint8_t peakHeartRate;
	
	//0xE here: time of workout start
	uint8_t year; /** 2 digit format -- century not stored */
	uint8_t month; //self explanatory
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t fileNumber1; //assigned sequentially
	
	//0x14 here, three (?) significative bytes that don't matter to the watch and lotsa padding
	uint16_t unknown1; // no idea at all
	uint8_t  gpsOff;
	uint16_t unknown2;
	uint16_t unknown3;
	uint16_t unknown4;
	uint16_t unknown5;
	uint16_t unknown6;
	uint16_t unknown7;
	uint16_t unknown8;
	
	//0x26 here
	uint8_t fileNumber2; //assigned sequentially
	uint8_t magicMarker1; //must be 0xFA
	
	//0x28 here, this section likely deals with the "target" feature as it's only nonzero in the one file I screwed with it during its recording; my match-noted-down-values research shows that stored values are those set just before stopping
	//from user manual, one of these should be "% of {time|distance\who knows} target was met"
	uint16_t targetTimeUndershot;
	uint16_t targetTimeOK;
	uint16_t targetTimeOvershot;
	uint16_t targetSpeedMinimum;
	uint16_t targetSpeedMaximum;
	uint8_t  targetHeartRateMinimum;
	uint8_t  targetHeartRateMaximum;
	uint8_t  targetMode;

	//0x35, padding again
	uint8_t  unknown15;
	uint16_t unknown16;
	uint16_t unknown17;
	uint8_t fileNumber3; /** should equal "fileNumber1" */
	uint8_t magicMarker2; /** must be 0xF0 */
	//End of file
	
	//phew!
	
	} OMHFile;
	
	

#endif
	