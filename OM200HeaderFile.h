#ifndef ONMOVE200_HEADER_FILE
	#define ONMOVE200_HEADER_FILE
	
	#include <stdint.h>
	
	typedef struct {
	//all numbers are little endian
	//field sizes for all "unknown*" are guesses

	//TODO further research needs a cardio belt (donations accepted, it's not my main priority though) or someone trusting me + willing to cooperate with data submissions
	
	//start of file (0x0)
	uint16_t distance; /** distance of workout in meters */
	uint16_t unknown1; /** always 0 in my samples -- just a guess: heart rate */
	uint16_t duration; /** duration of workout in seconds */
	uint16_t speed; /** average speed in decameters per hour = km/h * 100 */
	uint16_t unknown2; /** most likely: pace (i.e. reciprocal of speed) but not in obvious units */
	uint16_t energy; /** energy burned in kcal */
	uint16_t unknown3; /** another candidate for heart rate (even more likely given how, apart from unknown1, this file's format until here matches the default window setup on the watch) */
	
	//0xE here: time of workout start
	uint8_t year; /** 2 digit format -- century not stored */
	uint8_t month; //self explanatory
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	
	//0x14 here, three (?) significative bytes that don't matter to the watch and lotsa padding
	uint8_t unknown4; // no idea at all
	uint8_t unknown5; // always 0 in my samples
	uint8_t unknown6; // no idea at all
	uint16_t unknown7;
	uint16_t unknown8;
	uint16_t unknown9;
	uint16_t unknown10;
	uint16_t unknown11;
	uint16_t unknown12;
	uint16_t unknown13;
	
	//0x26 here
	uint8_t fileNumber1; //assigned sequentially
	uint8_t magicMarker1; //must be 0xFA
	
	//0x28 here, this section likely deals with the "target" feature as it's only nonzero in the one file I screwed with it during its recording; my match-noted-down-values research shows that stored values are those set just before stopping
	//from user manual, one of these should be "% of {time|distance\who knows} target was met"
	uint16_t unknownTarget1;
	uint16_t unknownTarget2;
	uint16_t unknownTarget3;
	uint16_t targetSpeedMinimum;
	uint16_t targetSpeedMaximum;
	
	//0x32 here, suspected padding again
	uint16_t unknown14;
	uint16_t unknown15;
	uint16_t unknown16;
	uint16_t unknown17;
	uint8_t fileNumber2; /** should equal "fileNumber1" */
	uint8_t magicMarker2; /** must be 0xF0 */
	//End of file
	
	//phew!
	
	} OMHFile;
	
	

#endif
	