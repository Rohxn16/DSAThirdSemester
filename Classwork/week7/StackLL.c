#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    Node* next;
}Node;


bool isEmpty(struct Node* top){
    return top == NULL;
}

bool isFull(struct Node* top){
    // create a new node to check if the memeory is available for reserving for a new node, if not the i.e. the temp node is null then it is full
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    return temp == NULL;
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
