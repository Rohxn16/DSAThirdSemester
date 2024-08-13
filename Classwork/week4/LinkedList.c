#include <stdio.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
} Node;

// insert at head should insert a node at the head by modifying original pointer
void insertAtHead(struct Node** head, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

// insert at tail should insert a node at the tail by modifying original pointer
void insertAtTail(struct Node** head, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    struct Node* ptr = *head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// insert at index should insert a node at the index by modifying original pointer
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

// delete at head should delete a node at the head by modifying original pointer
void deleteAtHead(struct Node** head){
    struct Node* ptr = *head;
    *head = (*head)->next;
    free(ptr);
}

// delete at tail should delete a node at the tail by modifying original pointer
void deleteAtTail(struct Node** head){
    struct Node* ptr = *head;
    struct Node* q = (*head)->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
}

// delete at index should delete a node at the index by modifying original pointer
void deleteAtIndex(struct Node** head, int index){
    struct Node* ptr = *head;
    struct Node* q = (*head)->next;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
}

void traverse(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d -->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// do functions with user input with a switch case
int main() {
    struct Node* head = NULL;
    int choice, value, index;

    do {
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at index\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at index\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the index: ");
                scanf("%d", &index);
                insertAtIndex(&head, value, index);
                break;
            case 4:
                deleteAtHead(&head);
                break;
            case 5:
                deleteAtTail(&head);
                break;
            case 6:
                printf("Enter the index: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 8);

    // traverse the newly created LL
    traverse(head);
    return 0;
}