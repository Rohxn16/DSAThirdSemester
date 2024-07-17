#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int top;
}Stack;

void init(Stack *stack){
    //set top to -1
    stack->top = -1;
}

bool isEmpty(Stack *stack){
    return stack->top == -1;
}

bool isFull(Stack *stack){
    return stack->top == SIZE-1;
}

void push(Stack *stack, int n){
    int index = stack->top;
    if(!isFull(stack)){
        stack->arr[++index] = n;
        ++stack->top;
    }else{
        printf("Stack is Full");
    }
}

int pop(Stack *stack){
    int curr;
    if(!isEmpty(stack)){
        curr = stack->arr[stack->top];    
        --stack->top;
    }else{
        printf("The stack is already empty\n");
        curr = -1; // Considering that our stack has only positive elements
    }
    return curr;
}

int peek(Stack *stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }else{
        return -1;
    }
}

void printStack(Stack *stack){
    for(int i = stack->top; i >= 0; i--){
        printf("%d\n",stack->arr[i]); // this is not the correct implementation, technically we should pop the stack each time to travel to thre previous element
    }
}

int main(int argc, char const *argv[])
{
    // Implementation
    Stack *stack;
    init(stack);
    push(stack,2);
    push(stack,3);
    push(stack,6);
    pop(stack);
    push(stack,8);
    printf("%d\n",peek(stack));
    printStack(stack);
    return 0;
}
