#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        printf("%d ", root->data);
        postorder(root->right);
    }
}

int main() {
    int choice;

    struct node* p = create_node(1);
    struct node* p2 = create_node(2);
    struct node* p4 = create_node(3);
    struct node* p5 = create_node(4);
    struct node* p6 = create_node(5);
    struct node* p7 = create_node(6);

    p->left = p2;
    p->right = p4;
    p2->left = p5;
    p2->right = p6;
    p4->left = p7;

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);

    return 0;
}


    /*struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 1;
    ptr->left = NULL;
    ptr->right = NULL;

    struct node* ptr1 = (struct node*)malloc(sizeof(struct node));
    ptr1->data = 2;
    ptr1->left = NULL;
    ptr1->right = NULL;

    struct node* ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2->data = 3;
    ptr2->left = NULL;
    ptr2->right = NULL;*/
