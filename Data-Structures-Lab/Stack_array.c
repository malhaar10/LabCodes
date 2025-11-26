#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
int top=-1;
int stack_arr[MAX];
bool isEmpty(){
    if(top == -1){
        printf("Stack empty");
        return true;
    }else{
        return false;
    }
}
bool isFull(){
    if(top == MAX - 1){
        printf("Stack is full");
        return true;
    }else{
        return false;
    }
}
void push(int data){
    if(isFull()){
        printf("Cannot push.");
        exit(0);
    }else{
        top++;
        stack_arr[top] = data;
    }
}
void pop(){
    if(isEmpty()){
        printf("Stack is empty.");
        exit(0);
    }else{
        top--;
        return stack_arr[top];
    }
}
void display(){
    for(int i = top; i >= 0; i--){
        printf("%d", stack_arr[i]);
    }
}
int main(){
    int choice,data;
    printf("Stack operations: \n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
    while(1){
        printf("\nEnter choice of operation: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                printf("Elements: ");
                display();
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice.");
            }
        }
    }
    return 0;
}
