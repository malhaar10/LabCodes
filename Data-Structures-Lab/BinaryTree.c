#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node* Create_node(int item){
    int x;
    if(item != -1){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = item;
        printf("Enter data:");
        scanf("%d", &item);
        temp->lchild = Create_node(x);
        printf("Enter data:");
        scanf("%d", &item);
        temp->rchild = Create_node(x);
        return temp;
    }
    return NULL;
}

void inorder(struct node* root){
    inorder(root-> lchild);
    printf("%d", root-> lchild);
    inorder(root-> rchild);
    printf("%d", root-> rchild);
}

void preorder(){

}

int main(){
    struct node* root = NULL;
    int item;
    printf("Create binary tree: ");
    scanf("%d", &item);
    root = Create_node(item);

}
