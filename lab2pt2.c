// Name: Carson Hom
// // Date: Thursday 9:15 October 1
// // Title: Lab1 step 5
// // Description: This program uses fork() to create exactly 7 different processes including the initial program itself

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
	pid_t pid;
	int i;
	printf("\nbefore forking \n");
	printf("parent pid %d\n", getpid());

	if(fork() == 0) { // Child
		printf("child1 pid %d from parent pid %d\n",getpid(),getppid());
		if(fork() == 0) { // Grandchild
			printf("child2 pid %d from parent pid %d\n",getpid(),getppid());
			exit(0);
		}
		else { // Grandchild 2
			if(fork() == 0) {
				printf("child3 pid %d from parent pid %d\n",getpid(),getppid());
				exit(0);
			}
			else {
				wait(NULL);
			}
			wait(NULL);
		}
		exit(0);
	}
	else { // Parent
		if(fork() == 0) { // Child
			printf("child4 pid %d from parent pid %d\n",getpid(),getppid());
			if(fork() == 0) { // Grandchild
				printf("child5 pid %d from parent pid %d\n",getpid(),getppid());
				exit(0);
			}
			else { // Grandchild 2
				if(fork() == 0) {
					printf("child6 pid %d from parent pid %d\n",getpid(),getppid());
					exit(0);
				}
				else {
					wait(NULL);
				}
				wait(NULL);
			}
			exit(0);
		}
		else {
			wait(NULL);
		}
		wait(NULL);
	}
	return 0;
}
		

