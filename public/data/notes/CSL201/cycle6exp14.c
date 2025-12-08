#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
    int data;
    struct node1* lchild;
    struct node1* rchild;
}node;

node* root;

void insert(node* root, int data){
    char ch;
    int item;
    root->data = data;
    
    printf("Enter left child for %d (y/n): ", data);
    scanf(" %c", &ch);
    if(ch=='y'){
        printf("Enter data: ");
        scanf(" %d", &item);
        node* lchild = (node*) malloc(sizeof(node));
        lchild->lchild = NULL;  
        lchild->rchild = NULL;
        root->lchild = lchild;
        insert(lchild, item);
    }
    else{
        root->lchild = NULL;
    }

    printf("Enter right child for %d (y/n): ", data);
    scanf(" %c", &ch);
    if(ch=='y'){
        printf("Enter data: ");
        scanf(" %d", &item);
        node* rchild = (node*) malloc(sizeof(node));
        rchild->lchild = NULL;  
        rchild->rchild = NULL;
        root->rchild = rchild;
        insert(rchild, item);
    }
    
}


void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->lchild);   
    postorder(root->rchild);
    printf("%d ", root->data);
}

node* findMin(node* root) {
    while(root->lchild != NULL) root = root->lchild;
    return root;
}

node* deleteNode(node* root, int data){
    if(root == NULL) return root;

    if(data != root->data) {
        root->lchild = deleteNode(root->lchild, data);
        root->rchild = deleteNode(root->rchild, data);
    } 
    else {
        if(root->lchild == NULL) {
            node* temp = root->rchild;
            free(root);
            return temp;
        } 
        else if(root->rchild == NULL) {
            node* temp = root->lchild;
            free(root);
            return temp;
        }

        node* temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }
    return root;
}

int main(){
    root = (node*) malloc(sizeof(node));
    root->lchild = NULL;
    root->rchild = NULL;

    insert(root, 0);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = deleteNode(root, 6);
    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");
}
