// Thread Sychronization

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <fcntl.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
//sem_t *mutex; 
pthread_mutex_t lock;

void* go(void* arg) { 
  //sem_wait(mutex); //entry section
  pthread_mutex_lock(&lock);
  printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
   sleep(1); 
  pthread_mutex_unlock(&lock);
  //sem_post(mutex); //exit section 
  return (NULL);
} 

int main() { 
//mutex = sem_open("mutex", O_CREAT, 0644, 1);
static int i;
for (i = 0; i < NTHREADS; i++)  
   pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
pthread_mutex_destroy(&lock);
//sem_unlink("mutex"); 
return 0; 
} 
