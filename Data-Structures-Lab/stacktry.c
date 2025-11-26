#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int top = -1;
int Stack_arr[MAX_SIZE];
void push(int data){
    if(top == MAX_SIZE-1){
        printf("Stack overflow.");
        return;
    }
    top++;
    Stack_arr[top] = data;
}
int pop(){
    if(top == -1){
        printf("Stack empty, nothing to remove.");
        exit(1);
    }
    int value = Stack_arr[top];
    top--;
}
void display(){
    if(top == -1){
        printf("Stack is empty, nothing to display.");
    }
    for(int i = top; i>=0 ;i--){
        printf("%d", Stack_arr[i]);
    }
}
int peek(){
    printf("Top element: ");
    return Stack_arr[top];
}
void isFull(){
    if(top == MAX_SIZE-1){
        printf("Stack overflow.");
        return 1;
    }
    printf("Stack is not full.");
    return 0;
}
void isEmpty(){
    if(top == -1){
        printf("Stack is empty, nothing to display.");
        return 1;
    }
    printf("Stack is not empty.");
    return 0;
}
int main(){
    int choice, data;
    printf("Stack operations: \n1. Push \n2. Pop \n3. Display \n4. Peek \n5.Check if full \n6. Check if empty \n7. Exit");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Element popped: %d", data);
            break;
        case 3:
            printf("The stack:");
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            isFull();
            break;
        case 6:
            isEmpty();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.");
        }
    }
    return 0;
}
