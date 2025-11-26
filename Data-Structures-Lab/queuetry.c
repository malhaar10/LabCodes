#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 5
int front=0, rear=-1;
int arr[MAX_SIZE];
bool isempty(){
    if(front<0 || front>rear){
        return true;
    }else{
        return false;
    }
}
bool isfull(){
    if(rear == MAX_SIZE-1){
        return true;
    }else{
        return false;
    }
}
void enqueue(int data){
   if(isfull()){
        printf("Queue full.");
        return 0;
   }else{
       rear++;
       arr[rear] = data;
   }
}
void dequeue(){
    if(isempty()){
        printf("Queue is empty.");
        exit(0);
    }else{
        printf("Deleted element is: %d", arr[front]);
        front++;
    }
}
void display(){
    if(isempty()){
        printf("Queue empty");
    }else{
        for(int i = front ; i<= rear ; i++){
            printf("Queue is: %d", arr[i]);
            printf(" ");
        }
    }
}
int main(){
    int choice, info;
    printf("Queue operations: ");
    printf("1.Enqueue  \n2.Dequeue  \n3.Display");
    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter ele,ment to enqueue: ");
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
