// need a user defined data structure that can store :
// an integer value
// a pointer to the next node

#include <stdio.h>
#include <stdlib.h>

// Node
struct Node{
    int value;
    struct Node* next;
}Node;

// functions: -> insertion, deletion, traverse.

struct Node head;

// 1->2->3 -> 7 ->4->5;
void traverseLinkedList(struct Node *head){
    struct Node *headPointer = head;
    while(headPointer != NULL){
        printf("%d -> ",headPointer->value);
        headPointer = headPointer->next;
    }
    printf("NULL\n");
}

void insert(struct Node *head, int val, int index){

    struct Node *headPointer = head;
    for(int i = 1; i <= index; i++){
        headPointer = headPointer->next;
    }
    // by the end of this loop head pointer is at its desired position
    struct Node* nextNode = headPointer->next; // storing the node from next of headPointer in order to reestablish the link later
    struct Node insertable;
    insertable.value = val;
    insertable.next = nextNode;
    headPointer->next = nextNode;
traverseLinkedList(head);
}

int main(int argc, char const *argv[])
{
    struct Node node1;
    node1.value = 5;
    
        struct Node node2;
    node2.value = 6;
    node2.next = &node1;
        struct Node node3;
    node3.value = 10;
    node3.next = &node2;
        struct Node node4;
    node4.value = 3;
    node4.next = &node3;

    head.value = 1;
    head.next = &node4;

    insert(&head,80,3);
    // traverseLinkedList(&head);
    return 0;
}
