#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

// circular linked list

void insertAtHead(struct Node** head, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    struct Node* ptr = *head;
    if(ptr != NULL){
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }else{
        temp->next = temp;
    }
    *head = temp;
}

void insertAtIndex(struct Node** head, int val, int index){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    struct Node* ptr = *head;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteAtHead(struct Node** head){
    struct Node* ptr = *head;
    struct Node* temp = *head;
    while(ptr->next != *head){
        ptr = ptr->next;
    }
    ptr->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
}

void deleteAtIndex(struct Node** head, int index){
    struct Node* ptr = *head;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    struct Node* temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
}

void printList(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

