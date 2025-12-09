#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}


void inorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void sortInputNumbers(struct Node* root) {
    printf("Sorted input numbers: ");
    inorderTraversal(root);
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    printf("1. Insert a new node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Delete a node\n");
    printf("6. Find the number of leaf nodes\n");
    printf("7. Sort the input numbers\n");
    printf("0. Exit");
    while (1) {
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Inorder traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Preorder traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Postorder traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Enter the value to delete: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                }
                break;

            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;

            case 7:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    sortInputNumbers(root);
                }
                break;

            default:
                exit(0);
        }
    }
    return 0;
}
