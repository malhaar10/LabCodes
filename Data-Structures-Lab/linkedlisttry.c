#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head, *newn, *trav;
void insert_at_beginning(int info){
    newn = (struct node*)malloc(sizeof(struct node));
    newn -> next=head;
    newn -> data=info;
}
void insert_in_between(){
    newn = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    int i=0;
    while(i != index-1){
        temp = temp-> next;
        i++;
    }
    newn->data = info;
    newn->next = temp->next;
    temp->next = newn;
    return head;
}
void insert_at_end(){
    struct node* temp = head;
    newn=(struct node*)malloc(sizeof(struct node));
    newn-> data=info;
    while(temp-> next!=NULL){
        temp-> temp=next;
        newn-> next=NULL;
        return head;
    }
}

void display(){
    trav = head;
    if(trav == NULL){
        printf("List is empty.");
        return 0;
    }else{
        printf("List is: ");
        while(trav != NULL){
            printf("\n%d", trav->data);
            printf("\n");
            trav = trav->next;
        }
    }
}
int main(){

    return 0;
}
