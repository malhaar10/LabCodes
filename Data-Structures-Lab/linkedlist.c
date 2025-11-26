#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted\n");
}
void insertLast(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("Node inserted\n");
}
void insertAtLocation(Node** head, int data, int position) {
    if (position == 1) {
        insertBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* current = *head;
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("Node inserted\n");
}
void deleteBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning\n");
}
void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
    printf("Node deleted from the last\n");
}
void deleteAfterLocation(Node** head, int position) {
    Node* current = *head;
    for (int i = 1; i < position; i++) {
        if (current == NULL || current->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Node deleted after specified location\n");
}
int search(Node* head, int key) {
    Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
void show(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL;
    int choice, value, position, key, result;
    while (1) {
        printf("\nName: Malhaar JAchak \nReg. No: 225811046\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert in beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete node after specified location\n");
        printf("7. Search for an element\n");
        printf("8. Show\n");
        printf("9. Exit\n");
        printf("Enter your choice? ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertLast(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtLocation(&head, value, position);
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAfterLocation(&head, position);
                break;
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = search(head, key);
                if (result != -1) {
                    printf("Element %d found at position %d\n", key, result);
                } else {
                    printf("Element %d not found in the list\n", key);
                }
                break;
            case 8:
                show(head);
                break;
            case 9:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
