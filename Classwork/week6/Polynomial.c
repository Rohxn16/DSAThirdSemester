#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coef;
    int degree;
    struct Node* next;
}Poly;

void printEquation(Poly* head){
    if(head == NULL){
        printf("0\n");
        return;
    }
    while(head != NULL){
        if(head->coef != 0){
            if(head->degree == 0){
                printf("%d", head->coef);
            }else if(head->degree == 1){
                if(head->coef == 1){
                    printf("x");
                }else{
                    printf("%dx", head->coef);
                }
            }else{
                if(head->coef == 1){
                    printf("x^%d", head->degree);
                }else{
                    printf("%dx^%d", head->coef, head->degree);
                }
            }
            if(head->next != NULL && head->next->coef > 0){
                printf(" + ");
            }
        }
        head = head->next;
    }
    printf("\n");
}

void insertAtEnd(Poly **head, int coef, int degree){
    Poly *newNode = (Poly*)malloc(sizeof(Poly));
    newNode->coef = coef;
    newNode->degree = degree;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Poly *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addEquations(Poly* eq1, Poly* eq2){
    Poly* result = NULL;
    while(eq1 != NULL && eq2 != NULL){
        if(eq1->degree == eq2->degree){
            insertAtEnd(&result, eq1->coef + eq2->coef, eq1->degree);
            eq1 = eq1->next;
            eq2 = eq2->next;
        }else if(eq1->degree > eq2->degree){
            insertAtEnd(&result, eq1->coef, eq1->degree);
            eq1 = eq1->next;
        }else{
            insertAtEnd(&result, eq2->coef, eq2->degree);
            eq2 = eq2->next;
        }
    }
    while(eq1 != NULL){
        insertAtEnd(&result, eq1->coef, eq1->degree);
        eq1 = eq1->next;
    }
    while(eq2 != NULL){
        insertAtEnd(&result, eq2->coef, eq2->degree);
        eq2 = eq2->next;
    }
    printEquation(result);
}

int main(int argc, char const *argv[])
{

    Poly *head = NULL;
    
    // insertAtEnd(&head, 1, 2);
    // insertAtEnd(&head, 2, 1);
    // insertAtEnd(&head, 3, 0);

    // dynamically fetching user input for 2 equations and processing them and adding them

    int n,coef,exp;
    printf("Enter the number of terms for the first equation ");
    scanf("%d",&n);
    while(n--){
    printf("Enter the coefficient and exponent of the current term separated by space or new line");
    scanf("%d %d",&coef,&exp);
    insertAtEnd(&head,coef,exp);
    }
    printEquation(head);

    Poly *head2 = NULL;
    // insertAtEnd(&head2, 1,3);
    // insertAtEnd(&head2, 4,2);
    // insertAtEnd(&head2, 5,1);
    // insertAtEnd(&head2, 6,0);
    printf("Enter the number of terms for the first equation ");
    scanf("%d",&n);
    while(n--){
    printf("Enter the coefficient and exponent of the current term separated by space or new line");
    scanf("%d %d",&coef,&exp);
    insertAtEnd(&head2,coef,exp);
    }
    printEquation(head2);

    addEquations(head, head2);
    return 0;
}
