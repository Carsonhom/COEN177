#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char buffer[atoi(argv[2])]; // buffer with size speicified by argv[2]
	FILE *fp;
	fp = fopen(argv[1], "rb"); // open file specified by argv[1]
	FILE *fpout;
	fpout = fopen("output.txt", "wb"); // output file
	while (fread(buffer, sizeof(buffer), 1, fp)){ // read in contents of argv[1] into the buffer
		fwrite(buffer, sizeof(buffer), 1, fpout); // write the contents of buffer into output file
	}
	fclose(fp);
	fclose(fpout);
	return 0;
}
