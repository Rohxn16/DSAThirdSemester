#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coefficient;
    int power;
    struct Node* next;
}Poly;

void insertAtEnd(Poly **head, int coeff, int pow){
    Poly* newNode = (Poly*) malloc (sizeof(Poly));
    newNode->coefficient = coeff;
    newNode->power = pow;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }else{
        Poly* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addEquations(Poly* eq1, Poly* eq2){
    Poly* result = NULL;
    while(eq1 != NULL && eq2 != NULL){
        if(eq1->power == eq2->power){
            insertAtEnd(&result,eq1->coefficient+eq2->coefficient,eq1->power);
            eq1 = eq1->next;
            eq2 = eq2->next;
        }
        else if(eq1->power > eq2->power){
            insertAtEnd(&result,eq1->coefficient,eq1->power);
            eq1 = eq1->next;
        }else{
            insertAtEnd(&result,eq2->coefficient,eq2->power);
            eq2 = eq2->next;
        }
    }

    while(eq1 != NULL){
        insertAtEnd(&result,eq1->coefficient,eq1->power);
        eq1 = eq1->next;
    }

    while(eq2 != NULL){
        insertAtEnd(&result,eq2->coefficient,eq2->power);
        eq2 = eq2->next;
    }

    printEquation(result);
}

void multiplyEquations(Poly* eq1, Poly* eq2){
    
}

void printEquation(Poly* head){
    Poly* temp = head;
    while(temp->next != NULL){
        printf("%dx^%d + ",temp->coefficient,temp->power);
        temp = temp->next;
    }
    printf("%dx^%d ",temp->coefficient,temp->power);

}


int main(int argc, char const *argv[])
{

    Poly* head = NULL;
    insertAtEnd(&head,1,3);
    insertAtEnd(&head,5,2);
    insertAtEnd(&head,9,1);
    printEquation(head);
    printf("\n");
    Poly* head2 = NULL;

    insertAtEnd(&head2,1,4);
    insertAtEnd(&head2,5,2);
    insertAtEnd(&head2,9,1);
    printEquation(head2);
    printf("\n");
    addEquations(head,head2);
    printf("\n");
    return 0;
}
