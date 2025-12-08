#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root;

node* queue[100];
int front=0, rear=0;

node* insert(node* root, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (root == NULL) 
        return newNode;
    queue[rear++] = root;

    while (front < rear) {
        node* current = queue[front++];
        if (current->left == NULL) {
            current->left = newNode;
            return root;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            return root;
        } else {
            queue[rear++] = current->right;
        }
    }
    return root;
}

void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    inorder(root);
    return 0;
}
