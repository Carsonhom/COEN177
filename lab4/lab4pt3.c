//Name: Carson
//Date: October 15 9:15
//Title: Lab4 task 3
//Description: This program uses threads to perform matrix multiplication

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define SIZE 3

void *matrixmult(void *);

double matrixA[SIZE][SIZE], matrixB[SIZE][SIZE], matrixC[SIZE][SIZE];
pthread_t threads[SIZE];
int main() {
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++) // Fill matrixA
		for(int j = 0; j < SIZE; j++)
			matrixA[i][j] = rand() % 10;
	for(int i = 0; i < SIZE; i++) { // Print matrixA
		for(int j = 0; j < SIZE; j++) {
			printf("%.1f ", matrixA[i][j]);
		}
		printf("\n");
	}
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++) // Fill matrixB
		for(int j = 0; j < SIZE; j++)
			matrixB[i][j] = rand() % 10;
	for(int i = 0; i < SIZE; i++) { // Print matrixB
		for(int j = 0; j < SIZE; j++) {
			printf("%.1f ", matrixB[i][j]);
		}
		printf("\n");
	}
	int i;
	for(i = 0; i < SIZE; i++)
		pthread_create(&threads[i], NULL, matrixmult, (void *)(size_t)i);
	for(i = 0; i < SIZE; i++)
		pthread_join(threads[i], NULL);
	
	printf("Main thread done.\n");

	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			printf("%.1f ", matrixC[i][j]);
		}
		printf("\n");
	}
}

void *matrixmult(void *arg) {
	for(int j = 0; j < SIZE; j++) {
		double temp = 0;
		for(int k = 0; k < SIZE; k++) {
			temp += matrixA[(int)arg][k] * matrixB[k][j];
		}
		matrixC[(int)arg][j] = temp;
	}
}
