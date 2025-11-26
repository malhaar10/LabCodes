#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

sem_t x, y;
pthread_t tid;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;

void *reader(void* param)
{
    sem_wait(&x);
    readercount++;
    if (readercount == 1) {
        sem_wait(&y); // First reader locks the writers
    }
    sem_post(&x);
    
    printf("\nReader %d is inside", readercount);
    
    // Critical section for reading can be placed here
    
    sem_wait(&x);
    readercount--;
    if (readercount == 0) {
        sem_post(&y); // Last reader unlocks the writers
    }
    sem_post(&x);
    
    printf("\nReader %d is leaving", readercount + 1);
    
    return NULL;
}

void *writer(void* param)
{
    printf("\nWriter is trying to enter");
    sem_wait(&y); // Writers lock semaphore y
    printf("\nWriter has entered");
    
    // Critical section for writing can be placed here
    
    sem_post(&y);
    printf("\nWriter is leaving");
    
    return NULL;
}

int main()
{
    int n2, n1, i;
    printf("Enter the number of readers: ");
    scanf("%d", &n2);
    printf("Enter the number of writers: ");
    scanf("%d", &n1);

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    
    // Create reader threads
    for (i = 0; i < n2; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL);
    }

    // Create writer threads
    for (i = 0; i < n1; i++) {
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    }

    // Join reader threads
    for (i = 0; i < n2; i++) {
        pthread_join(readerthreads[i], NULL);
    }

    // Join writer threads
    for (i = 0; i < n1; i++) {
        pthread_join(writerthreads[i], NULL);
    }
    
    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}
