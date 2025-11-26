#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
int front = 0, rear = -1, count = 0;
int arr[MAX];
bool isfull(){
    if(count == MAX){
        return true;
    }else{
        return false;
    }
}
bool isempty(){
    if(count == 0){
        return true;
    }else{
        return false;
    }
}
void enqueue(int data){
    if(isfull()){
        printf("Queue is full.");
        exit(0);
    }else{
        rear = (rear+1) % MAX;
        arr[rear] = data;
        count++;
    }
}
void dequeue(){
    if(isempty()){
        printf("Queue is empty.");
        exit(0);
    }else{
        printf("Element deleted: %d", arr[front]);
        front = (front+1) % MAX;
        count--;

    }
}
void display(){
    if(isempty()){
        exit(0);
    }else{
        printf("Queue is: ");
        for(int i=0; i<= count; i++){
            printf(" ", &arr[i]);
        }
    }
}
int main(){
    int choice, info;
    printf("Queue operations: \n");
    printf("\n1.Enqueue  \n2.Dequeue  \n3.Display \n");
    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &info);
            enqueue(info);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("The queue is: ");
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid choice.");
        }
    }
    return 0;
}
