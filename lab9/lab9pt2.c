#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char buffer[10000]; //buffer of size 100000
	FILE *fp;
	fp = fopen(argv[1], "rb"); // open the file specified by argv[1]
	while (fread(buffer, sizeof(buffer), 1, fp)) { // read the contents of the file into the buffer
	}
	close(fp);
	return 0;
}
