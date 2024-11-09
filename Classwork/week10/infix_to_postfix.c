#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct Stack{
    char arr[MAX];
    int top;
}Stack;

void push(char ch, Stack *ptr){
    if(ptr->top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = ch;
}

char pop(Stack *ptr){
    if(ptr->top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    char ch = ptr->arr[ptr->top];
    ptr->top--;
    return ch;
}

int isEmpty(Stack *ptr){
    return ptr->top == -1;
}

char stackTop(Stack *ptr){
    return ptr->arr[ptr->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/') return 3;
    else if(ch == '+' || ch == '-') return 2;
    else return 1;
}

void infixToPostfix(char *infix, char *postfix){
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(isEmpty(&s) || precedence(infix[i]) > precedence(stackTop(&s))){
                push(infix[i++], &s);
            }
            else{
                postfix[j++] = pop(&s);
            }
        }
    }
    while(!isEmpty(&s)){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
    return 0;
}

