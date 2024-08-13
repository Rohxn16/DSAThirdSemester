#include <stdio.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insertAtHead(struct Node** head, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL){
        (*head)->prev = temp;
    }
    *head = temp;
}

void insertAtTail(struct Node** tail, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = *tail;
    if(*tail != NULL){
        (*tail)->next = temp;
    }
    *tail = temp;
}

void insertAtIndex(struct Node** head, int val, int index){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    struct Node* ptr = *head;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    if(ptr->next != NULL){
        ptr->next->prev = temp;
    }
    ptr->next = temp;
}

void deleteAtHead(struct Node** head){
    struct Node* ptr = *head;
    *head = (*head)->next;
    if(*head != NULL){
        (*head)->prev = NULL;
    }
    free(ptr);
}

void deleteAtTail(struct Node** tail){
    struct Node* ptr = *tail;
    *tail = (*tail)->prev;
    if(*tail != NULL){
        (*tail)->next = NULL;
    }
    free(ptr);
}

void deleteAtIndex(struct Node** head, int index){
    struct Node* ptr = *head;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = ptr;
    }
    free(temp);
}

void traverseFromHead(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void traverseFromTail(struct Node* tail){
    struct Node* ptr = tail;
    while(ptr != NULL){
        printf("%d ->", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = head;
    int choice, val, index;

    while (1) {
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at index\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at index\n");
        printf("7. Traverse from head\n");
        printf("8. Traverse from tail\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertAtTail(&tail, val);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the index: ");
                scanf("%d", &index);
                insertAtIndex(&head, val, index);
                break;
            case 4:
                deleteAtHead(&head);
                break;
            case 5:
                deleteAtTail(&tail);
                break;
            case 6:
                printf("Enter the index: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                traverseFromHead(head);
                break;
            case 8:
                traverseFromTail(tail);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}