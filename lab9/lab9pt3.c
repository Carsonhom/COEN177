#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char buffer[atoi(argv[2])]; // buffer with size specified by argv[2]
	FILE *fp; 
	fp = fopen(argv[1], "rb"); // open file specified by argv[1]
	while (fread(buffer, sizeof(buffer), 1, fp)){ // read in contents of file into buffer
	}
	fclose(fp);
	return 0;
}
