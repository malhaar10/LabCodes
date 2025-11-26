#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5  // Buffer capacity

int buffer[BUFFER_SIZE];
int in = 0, out = 0;   // Indices for buffer

// Semaphores and mutex
sem_t empty;   // Counts the empty slots in the buffer
sem_t full;    // Counts the full slots in the buffer
pthread_mutex_t mutex; // Mutex for mutual exclusion

void *producer(void *arg) {
    int produced_item;
    for (int i = 0; i < 10; i++) {  // Producing 10 items
        produced_item = rand() % 100;  // Produce a random item

        // Wait for an empty slot
        sem_wait(&empty);
        // Lock the buffer using mutex
        pthread_mutex_lock(&mutex);

        // Critical section: Add the item to the buffer
        buffer[in] = produced_item;
        printf("Producer produced: %d at index %d\n", produced_item, in);
        in = (in + 1) % BUFFER_SIZE;  // Circular buffer

        // Unlock the buffer and signal that an item is added
        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        // Simulate some delay for production
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int consumed_item;
    for (int i = 0; i < 10; i++) {  // Consuming 10 items

        // Wait for a full slot
        sem_wait(&full);
        // Lock the buffer using mutex
        pthread_mutex_lock(&mutex);

        // Critical section: Remove the item from the buffer
        consumed_item = buffer[out];
        printf("Consumer consumed: %d from index %d\n", consumed_item, out);
        out = (out + 1) % BUFFER_SIZE;  // Circular buffer

        // Unlock the buffer and signal that an item was consumed
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        // Simulate some delay for consumption
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE); // Initialize to buffer size (5 empty slots)
    sem_init(&full, 0, 0);            // Initialize to 0 full slots
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Cleanup: destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}