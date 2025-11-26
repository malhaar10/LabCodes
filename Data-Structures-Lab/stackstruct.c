#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
struct stack{
    int top, stk[MAX];
};
typedef struct stack Stack;
Stack s;
bool isEmpty(){
    if(s.top == -1){
        printf("Stack empty");
        return true;
    }else{
        return false;
    }
}
bool isFull(){
    if(s.top == MAX - 1){
        printf("Stack is full");
        return true;
    }else{
        return false;
    }
}
void push(int data){
    if(isFull()){
        printf("Cannot push.");
    }else{
        s.top++;
        s.stk[s.top] = data;
    }
}
void pop(){
    if(isEmpty()){
        printf("Stack is empty.");
    }else{
        s.top--;
        return s.stk[s.top];
    }
}
void display(){
    for(int i = s.top; i >= 0; i--){
        printf("%d", s.stk[i]);
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
