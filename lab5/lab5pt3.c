//Name: Carson Hom
//Date: 10/22 9:15
//Title: Lab5 task 3
//Description: Producer-Consumer problem solved using semaphores

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define NTHREADS 10
#define n 10
pthread_t threads[NTHREADS];
int in, out;
int buffer[n];
sem_t *mutex;	//
sem_t *empty;	// empty = n, if == 0 then buffer is full
sem_t *full;	// full = 0, if == 0 then buffer is empty

void* consumer(void* arg) {			// Consumer
	do{
		sem_wait(full);			// Wait until buffer is full
		sem_wait(mutex);		// Entry point for critical section
		int item = buffer[out];		// Take item out of buffer
		out = (out + 1) % n;		// Increment out index
		sem_post(mutex);		// Exit critical section
		sem_post(empty);
		printf("\tConsumed item %d\n", item);
	} while(1);
	
}

void* producer(void* arg) {			// Producer
	do {
		int item = rand() % 10;		// Create item to be put into buffer		
		sem_wait(empty);		// Wait for consumer to empty buffer if full
		sem_wait(mutex);		// Entry point for critical section
		buffer[in] = item;		// Put item into buffer
		in = (in + 1) % n;		// Increment in index
		sem_post(mutex);		// Exit critical section
		sem_post(full);
		printf("Produced item %d\n", item);
	} while(1);
}
			



int main() {
	mutex = sem_open("Mutex", O_CREAT, 0644, 1);
	empty = sem_open("Empty", O_CREAT, 0644, n);
	full = sem_open("Full", O_CREAT, 0644, 0);
	in = out = 0;
	int i;
	for(i = 0; i < NTHREADS / 2; i++) {	// Create producers
		pthread_create(&threads[i], NULL, producer, (void *)(size_t)i);
	}
	for(i = NTHREADS / 2; i < NTHREADS; i++) { // Create consumers
		pthread_create(&threads[i], NULL, consumer, (void *)(size_t)i);
	}
	for(i = 0; i < NTHREADS; i++) {		// Wait for all threads to terminate
		pthread_join(threads[i], NULL);
	}
	sem_unlink("Mutex");
	sem_unlink("Empty");
	sem_unlink("Full");
	return 0;
}
