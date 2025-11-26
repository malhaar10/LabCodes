#include <stdio.h>
#include <stdlib.h>

// Define a structure for a program
struct Program {
    char name[50];
    int priority;
};

// Define a structure for a priority queue
struct PriorityQueue {
    struct Program *array;
    int capacity;
    int size;
};

// Function to create a new priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->array = (struct Program*)malloc(capacity * sizeof(struct Program));
    return queue;
}

// Function to swap two programs
void swap(struct Program* a, struct Program* b) {
    struct Program temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the queue based on program priority
void heapify(struct PriorityQueue* queue, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left].priority > queue->array[largest].priority) {
        largest = left;
    }

    if (right < queue->size && queue->array[right].priority > queue->array[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&queue->array[index], &queue->array[largest]);
        heapify(queue, largest);
    }
}

// Function to add a program to the priority queue
void enqueue(struct PriorityQueue* queue, struct Program program) {
    if (queue->size == queue->capacity) {
        printf("Queue is full. Cannot enqueue program.\n");
        return;
    }

    int i = queue->size;
    queue->array[i] = program;
    queue->size++;

    while (i > 0 && queue->array[(i - 1) / 2].priority < queue->array[i].priority) {
        swap(&queue->array[i], &queue->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Program '%s' with priority %d added to the queue.\n", program.name, program.priority);
}

// Function to display the programs in the priority queue
void displayQueue(struct PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue Contents:\n");
    for (int i = 0; i < queue->size; i++) {
        printf("Program: %s, Priority: %d\n", queue->array[i].name, queue->array[i].priority);
    }
}

int main() {
    int capacity, choice;
    printf("Enter the capacity of the priority queue: ");
    scanf("%d", &capacity);
    struct PriorityQueue* queue = createPriorityQueue(capacity);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue Program\n");
        printf("2. Display Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Program program;
                printf("Enter the program name: ");
                scanf("%s", program.name);
                printf("Enter the program priority: ");
                scanf("%d", &program.priority);
                enqueue(queue, program);
                break;
            }
            case 2: {
                displayQueue(queue);
                break;
            }
            case 3: {
                free(queue->array);
                free(queue);
                exit(0);
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
