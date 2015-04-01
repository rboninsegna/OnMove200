#ifndef ONMOVE200_DATA_FILE
	#define ONMOVE200_DATA_FILE
	
	#include <stdint.h>
	
	struct positionEntry{
	//all numbers are little endian
	//field sizes for all "unknown*" are guesses

	//TODO further research needs a cardio belt (donations accepted, it's not my main priority though) or someone trusting me + willing to cooperate with data submissions
	
	int32_t latitude; /** Latitude in degrees.decimals / 1000000 */
	int32_t longitude; /** Latitude in degrees.decimals / 1000000 */
	int32_t unknown1;
	int32_t unknown2;
	int16_t unknown3;
	int8_t  unknown4;
	int8_t  magic; /** Must be 0xF1 */
	}
	
	struct paddingEntry {
		int32_t unknown1;
		int32_t unknown2;
		int32_t unknown3;
		int32_t unknown4;
		int16_t unknown5;
		int8_t  unknown6;
		int8_t  magic; /** Must be 0xF2 */
	}
	//End of file
	//phew!
	
	};
	
	
	/* typedef struct {
		struct positionEntry;
		struct positionEntry;
		struct paddingEntry;
	} OMDFileBlock; */
	

#endif