#include <stdio.h>
#include <stdlib.h>
#include "OM200HeaderFile.h"

int main(int argc, char **argv)
{
	
	switch (argc) { //Check presence of argument
		case 2:
			break;
		default:
			fprintf(stderr,"Missing filename!\n");
			fprintf(stderr,"Usage: %s ACT_????.OMH\n",argv[0]);
			exit(255);
	}
	
	
	FILE* fd = fopen(argv[1],"rb");
	if (fd == NULL) { //Check presence of file
		fprintf(stderr, "%s can't open %s\n", argv[0],argv[1]);
		exit(10);
	}
	
	//load data into memory
	OMHFile header;
	fread(&header, sizeof header, 1, fd);
	fclose(fd);
	
	int validity=isRealisticallyOMH(&header);
	switch (validity) {
		case 1: //Magic number verification failed
		case 2:
			fprintf(stderr, "%s: %s isn't an OnMove 200 data header file\n", argv[0],argv[1]);
			exit(1);
		case 10: //File numbers not matching. I'm not sure this is an 8 bit number or for that matter if they are supposed to be equal...
			fprintf(stderr, "%s: %s doesn't appear to be an OnMove 200 data header file\n -- or my assumptions are wrong!\n", argv[0],argv[1]);
			exit(1);
		default: //Nothing of the above failed -- go on
			break;
	}
	
	
	
	printf("Greetings, fellow OnMove 200 user!\n");
	printf("Thank you for trying out this tech demo\n of what will hopefully end up as a completely unofficial\n data importing tool for our watch...\n");
	printf("On 2015-3-30, I contacted Geonaute support about .OMD and .OMH format.\n They replied promptly and politely, but were ultimately useless\n blabbing how they didn't write the software, NDA bullshit, etc\n and so I've been doing this alone...\n");
	printf("\n");
	printf("Please compare the data that follows with what you know,\n and send feedback to rboninsegna2@gmail.com :)\n");
	printf("\n");
	
	
	printf("Data file %s:\n",argv[1]);
	printf(" File number: %u\n", header.fileNumber2);
	printf(" Activity started on: 20%02u-%02u-%02u, %02u:%02u:%02u\n", header.year, header.month, header.day, header.hour, header.minute, header.second); //"%02u" = unsigned int, add zeroes to 2 digits
	printf(" Duration:  %02u:%02u:%02u (%u s)\n", header.duration/3600, header.duration/60, header.duration%60, header.duration);
	printf(" Distance:  %.2f km (%u m)\n", getDistanceKilometers(&header), getDistanceMeters(&header) );
	printf(" Speed:     %.2f km/h (approx. %.4f m/s)\n", getSpeedKilometersPerHour(&header), getSpeedMetersPerSecond(&header) );
	printf(" Energy:    %u kcal\n", getKilocaloriesBurned(&header));
	
	return 0;
}
