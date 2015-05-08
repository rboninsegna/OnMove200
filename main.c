#include <stdio.h>
#include <stdlib.h>
#include "OM200HeaderFile.h"

int main(int argc, char **argv) {
	//Check presence of argument
	switch (argc) {
		case 2:
			break;
		default:
			fprintf(stderr,"Missing filename!\n");
			fprintf(stderr,"Usage: %s ACT_????.OMH\n",argv[0]);
			exit(255);
	}
	
	
	FILE* fd = fopen(argv[1],"rb");
	//Check presence of file
	if (fd == NULL) {
		fprintf(stderr, "%s can't open %s\n", argv[0],argv[1]);
		exit(10);
	}
	
	//load data into memory
	OMHFile header;
	fread(&header, sizeof header, 1, fd);
	fclose(fd);
	
	{ //give up if checks fail
		int validity=isRealisticallyOMH(&header);
		switch (validity) {
			case 1: //Magic number verification failed
			case 2:
				fprintf(stderr, "%s: %s isn't an OnMove 200 data header file\n", argv[0],argv[1]);
				exit(1);
			case 6:
			case 7: //File numbers not matching. I'm not sure they are supposed to be equal...
				fprintf(stderr, "%s: %s doesn't appear to be an OnMove 200 data header file\n -- or my assumptions are wrong!\n", argv[0],argv[1]);
				exit(1);
			default: //Nothing of the above failed -- go on
				break;
		}
	}
	
	/*
	printf("Greetings, fellow OnMove 200 user!\n");
	printf("Thank you for trying out this tech demo\n of what will hopefully end up as a completely unofficial\n data importing tool for our watch...\n");
	printf("On 2015-3-30, I contacted Geonaute support about .OMD and .OMH format.\n They replied promptly and politely, but were ultimately useless\n blabbing how they didn't write the software, NDA bullshit, etc\n and so I've been doing this alone...\n");
	printf("\n");
	printf("Please compare the data that follows with what you know,\n and send feedback to rboninsegna2@gmail.com :)\n");
	printf("\n");
	*/
	
	printf("Data file %s:\n",argv[1]);
	printf(" File number: %u\n", header.fileNumber2);
	
	printf(" Activity started on: %u-%u-%u %u:%u\n",
		getYear(&header),getMonth(&header),getDay(&header),getHour(&header),getMinute(&header));
	
	{
		unsigned long D = getDurationSeconds(&header);
		printf(" Duration:   %uh %um %us\n", D/3600, D/60, D%60);
	}

	if (wasGpsEnabled(&header)) {
		printf(" Distance:   %.2f km (%u m)\n", getDistanceKilometers(&header), getDistanceMeters(&header) );
		printf(" Speed:      %.2f km/h\n", getSpeedKilometersPerHour(&header) );
		printf(" Top Speed:  %.2f km/h\n", getMaxSpeedKilometersPerHour(&header) );
		printf(" Energy:     %u kcal\n", getKilocaloriesBurned(&header));
	}

	if (getHeartRate(&header) != 0) { //is there a bit that tells if a cardio belt was connected?
		printf(" Heart rate: %u bpm (maximum: %u)\n", getHeartRate(&header), getMaxHeartRate(&header));
	}

	return 0;
}
