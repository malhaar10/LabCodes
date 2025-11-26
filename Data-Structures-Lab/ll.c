#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next; // Use "struct node*" instead of "node*"
};

// Declare global variables
struct node* head = NULL; // Initialize head to NULL

// Function to insert a node at the front of the linked list
void insert_front(int item) {
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    newn->data = item;
    if (head == NULL) {
        newn->next = NULL;
        head = newn;
    } else {
        newn->next = head;
        head = newn;
    }
}

// Function to insert a node at the rear of the linked list
void insert_rear(int item) {
    struct node* temp = head;
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    newn->data = item;
    newn->next = NULL; // Ensure the new node points to NULL initially
    if (head == NULL) {
        head = newn;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

// Function to delete the node at the front of the linked list
void delete_front() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_rear(){
    head = temp
}

// Function to display the elements of the linked list
void display() {
    struct node* trav = head;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

int main() {
    int choice, item;

    do {
        printf("1. Insert Front 2. Insert Rear 3. Delete Front 4. Display 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &item);
                insert_front(item);
                break;
            case 2:
                printf("Enter data to insert at the rear: ");
                scanf("%d", &item);
                insert_rear(item);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}
