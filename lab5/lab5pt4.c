//Name: Carson Hom
//Date: 10/22 9:15
//Title: Lab5 part 4
//Description: This program solves the consumer-producer provlem using conditional variables

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define NP 3
#define NC 2
#define n 10
pthread_t tidP[NP], tidC[NC];
int buffer[n];
pthread_mutex_t mutex;
pthread_cond_t full, empty;
int p, c, in, out, count;

void* producer(void* arg) {
	do {
		int item = rand() % 10;
		pthread_mutex_lock(&mutex);
		while(count == n)
			pthread_cond_wait(&empty, &mutex);
		buffer[in] = item;
		in = (in + 1) % n;
		count++;
		pthread_cond_signal(&full);
		pthread_mutex_unlock(&mutex);
		printf("Produced %d\n", item);
		sleep(1);
	} while(1);
}

void* consumer(void* arg) {
	do {
		pthread_mutex_lock(&mutex);
		while(count == 0)
			pthread_cond_wait(&full, &mutex);
		int item = buffer[out];
		out = (out + 1) % n;
		count--;
		pthread_cond_signal(&empty);
		pthread_mutex_unlock(&mutex);
		printf("\tConsumed %d\n", item);
		sleep(1);
	} while(1);
}

int main() {
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&empty, NULL);
	pthread_cond_init(&full, NULL);
	for(p = 0; p < NP; p++)
		pthread_create(&tidP[p], NULL, producer, (void*)(size_t)p);
	for(c = 0; c < NC; c++)
		pthread_create(&tidC[c], NULL, consumer, (void*)(size_t)c);
	for(p = 0; p < NP; p++) {
		pthread_join(tidP[p], NULL);
		printf("Producer thread %d returned\n", p);
	}
	for(c = 0; c < NC; c++) {
		pthread_join(tidC[c], NULL);
		printf("\tConsumer thread %d returned\n", c);
	}
	printf("Main thread finished\n");
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&full);
	pthread_cond_destroy(&empty);
	return 0;
}
