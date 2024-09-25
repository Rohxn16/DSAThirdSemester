#include <stdio.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}bst;

bst *createNode(int data){ // a simple helper function to create node
    bst *newNode = (bst*)malloc(sizeof(bst));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(bst **root, int data){
    if(*root == NULL){
        *root = createNode(data);
    }else{
        if(data < (*root)->data){
            insert(&(*root)->left, data);
        }else{
            insert(&(*root)->right, data);
        }
    }
}

void inorder(bst *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(bst *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(bst *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int countNodes(bst *root){
    if(root == NULL) return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left+right;
}

int main(){
    bst *root = NULL;
    int choice, data;

    while(1) {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
return 0;
}