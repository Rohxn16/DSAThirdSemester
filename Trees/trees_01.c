#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

void traverseInOrder(Node* root){
  // in order traversal printing of the tree from the given head address

  if(root == NULL) return;

  traverseInOrder(root->left);
  printf("%d ",root->data);
  traverseInOrder(root->right);
}

void traversePreOrder(Node* root){
  if(root == NULL) return;

  printf("%d ",root->data);
  traversePreOrder(root->left);
  traversePreOrder(root->right);
}

void traversePostOrder(Node* root){
  if(root == NULL) return;

  traversePostOrder(root->right);
  printf("%d ",root->data);
  traversePostOrder(root->left);

}

Node* createNewNode(int data){
  Node* node = (Node*)malloc(sizeof(Node)); // reserving space for the new node.
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main(){

  Node* root = createNewNode(5);
  root->left = createNewNode(3);
  root->right = createNewNode(2);
  root->left->left = createNewNode(1);
  root->left->right = createNewNode(0);
  root->right->left = createNewNode(7);
  root->right->left = createNewNode(9);
  traverseInOrder(root);
  printf("\n");
  traversePreOrder(root);
  printf("\n");
  traversePostOrder(root);
  printf("\n");
  return 0;
}
