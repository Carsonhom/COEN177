// Name: Carson Hom
// Date: Thursday 9:15 October 1
// Title: lab2 step 6
// Description: This program operates similarly to the program from step 1 but creates threads instead of processes

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void* onethread(void *i); /* {
	int j = *((int *) i);
	for(int k=0;k<100;k++) {
		printf("\t \t \t Thread 1 %d \n",k);
		usleep(j);
	}
	return 0;
}*/

void* twothread(void *i); /* {
	int j = *((int *) i);
	for(int k=0;k<100;k++) {
		printf("\t \t \t Thread 2 %d \n", i);
		usleep(j);
	}
	return 0;
}*/

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
	int *i = malloc(sizeof(*i));
	*i = n;
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, onethread, i);
	pthread_create(&thread2, NULL, twothread, i);
	pthread_join(thread1, NULL); // Wait for thread1 to execute
	pthread_join(thread2, NULL); // Wait for thread2 to execute
	return 0;
}

void* onethread(void *i) {
	int j = *((int *) i);
	for(int k=0;k<100;k++) {
		printf("\t \t \t Thread 1 %d \n",k);
		usleep(j);
	}
	return 0;
}

void* twothread(void *i) {
	int j = *((int *) i);
	for(int k=0;k<100;k++) {
 		printf("Thread 2 %d \n",k);
		usleep(j);
	}
	return 0;
}
