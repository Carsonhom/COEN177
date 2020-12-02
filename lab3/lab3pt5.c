//Name: Carson Hom
//Date: October 8 Thursday 9:15
//Title: Lab 3 task 5
//Description: C program which implements the producer-consumer message communication using pipes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fds[2];
	pipe(fds);
	char buff[60];
	int count;
	int i;
	//child 1 creates producer
	if (fork()==0) {
		printf("Producer\n");
		close(fds[0]);
		char input[60];
		scanf("%s", input);
		write(fds[1],input,strlen(input));
		exit(0);
	}
	//child 2 creates consumer
	else if (fork()==0) {
		close(fds[1]);
		while((count = read(fds[0],buff,60)) > 0) {
			printf("Consumer\n");
			printf("%s",buff); 
			printf("\n");
		}
		//read(fds[0],buff,60);
		/*for(i = 0; i < 60; i++) {
			printf(buff[i]);
		}*/
		//printf("%d",(char *) buff);
		//write(1,buff,60);
		exit(0);
	}
	else { //parent closes both ends and waits for children	
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0);
	}
	return 0;
}

