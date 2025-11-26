#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    char post[10];
    struct Node* next;
};
struct Node* head = NULL;
int postnum = 0;
void addNode(int data, const char* post) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    strcpy(newNode->post, post);
    newNode->next = head;
    head = newNode;
}
void initiate() {
    for (int i = 0; i < 5; i++) {
        char post[10] = "post";
        addNode(i + 1, post);
    }
    postnum = 5;
    printf("Initialization complete!\n");
    display();
}
void refresh() {
    system("cls");

    for (int i = 0; i < 5; i++) {
        char post[10] = "post";
        addNode(++postnum, post);
    }
    display();
}
void notInterested(int index) {
    if (index <= 0) {
        printf("Invalid index. Please enter a positive index.\n");
        return;
    }
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (index == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node at index %d deleted successfully!\n", index);
    } else {
        struct Node* current = head;
        int i = 1;
        while (i < index - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        if (current->next == NULL) {
            printf("Node at index %d not found.\n", index);
        } else {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Node at index %d deleted successfully!\n", index);
        }
    }
    display();
}
void display() {
    if (head == NULL) {
        printf("Feed is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Feed:\n");
    while (current != NULL) {
        printf("Post: %s %d\n", current->post, current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    int choice, index;
    do {
        printf("Menu:\n");
        printf("1. Initiate\n");
        printf("2. Refresh\n");
        printf("3. Not-Interested\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initiate();
                break;
            case 2:
                refresh();
                break;
            case 3:
                printf("Enter the index of the node to delete: ");
                scanf("%d", &index);
                notInterested(index);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
