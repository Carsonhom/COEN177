// Name: Carson Hom
// Date: Thursday 9:15 October 1
// Title: Lab1 step 1-4
// Description: This program uses fork() to create multiple processes

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	int i, n = atoi(argv[i]); // n microseconds to input from keyboard for delay
	printf("\n Before forking.\n");
	pid = fork();
	if (pid == -1) {
		fprintf(stderr, "can't fork, error %d\n", errno);
	}
	if (pid) {
		//Parent process
		for (i=0;i<100;i++) {
			printf("\t \t \t Parent Process %d \n",i);
			usleep(n);
		}
	}
	else{
		//Child process
		for (i=0;i<100;i++) {
		printf("Child process %d\n",i);
		usleep(n);
		}
	}
	return 0;
}
