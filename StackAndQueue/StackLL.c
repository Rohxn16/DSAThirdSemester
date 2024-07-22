#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
} Node;

void traverse(struct Node* ptr){
    while(ptr != NULL){
        printf("%d -->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

bool isEmpty(struct Node* top){
    return top == NULL;
}

bool isFull(struct Node* top){
    // create a new node to check if the memeory is available for reserving for a new node, if not the i.e. the temp node is null then it is full
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    return temp == NULL;
}

struct Node* push(struct Node* top, int val){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = top;
        top = temp;
    }
    return top;
}

struct Node* pop(struct Node* top){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }else{
        top = top->next;
    }
    return top;
}

int main(){
    struct Node* top = NULL;
    top = push(top,15);
    top = push(top,12);
    top = push(top,10);
    top = push(top,5);
    top = pop(top);
    top = push(top,0);
    traverse(top);

return 0;
}
