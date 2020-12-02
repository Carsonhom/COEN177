#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	pid_t  pid;
	int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
	printf("\n Before forking.\n");
	pid = fork();
	if (pid == -1) {
		fprintf(stderr, "can't fork, error %d\n", errno);
	}
	if (pid){
		// Parent process
		for (i=0;i<100;i++) {
			printf("\t \t \t Parent Process %d \n",i);
			usleep(n);
		}
	}
	else if(pid == 0) {
		execlp("/bin/ls","ls",NULL);
	}
	else{
		// Child process
		for (i=0;i<100;i++) {
			printf("Child process %d\n",i);
			usleep(n);
		}
		wait(NULL);
		printf("Child Complete");
		exit(0);
	}
	return 0;
}
