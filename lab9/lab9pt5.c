#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

char inputf[20]; // name of input file
int buffersize; // size of buffer specified by argv[2]

void *go(void *arg) { // thread function
	char buffer[buffersize]; // buffer with size specified by argv[2]
	//char buffer2[buffersize];
	FILE *fp;
	FILE *fpout;
	char fout[20]; // name of output file
	sprintf(fout, "output%d.txt", (int)arg); // append thread number to the name of the output file
	fp = fopen(inputf, "rb");
	fpout = fopen(fout, "wb");
	while (fread(buffer, sizeof(buffer), 1, fp)) { // read contents of input file into the buffer
		fwrite(buffer, sizeof(buffer), 1, fpout); // write contents of buffer into the output file
	}
	fclose(fp);
	fclose(fpout);
	return NULL;
}

int main(int argc, char *argv[]) {
	int i;
	int NTHREADS = atoi(argv[3]); // number of threads specified by argv[3]
	pthread_t threads[NTHREADS]; // array of threads
	strcpy(inputf, argv[1]); 
	buffersize = atoi(argv[2]);
	for(i = 0; i < NTHREADS; i++) // create number of threads specified by argv[3]
	{
		pthread_create(&threads[i], NULL, go, (void*)(size_t)i);
	}
	for(i = 0; i < NTHREADS; i++) // close all threads
	{
		pthread_join(threads[i], NULL);
	}	
	return 0;
}
