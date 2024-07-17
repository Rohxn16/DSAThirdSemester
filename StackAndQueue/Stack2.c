// An improved application of the stack data structure
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int top;
    int *arr;
}Stack;

void init(Stack *stack, int size){
    stack->arr = (int*)malloc(size * sizeof(int));

    if(stack->arr == NULL){
        printf("Could not reserve memory for allocation to stack\n");
        exit(1);
    }

    stack->top = -1;
    stack->size = size;
}

bool isEmpty(Stack *stack){
    return stack->top == -1;
}

bool isFull(Stack *stack){
    return stack->top == stack->size-1;
}

void push(Stack *stack, int num){
    if(!isFull(stack)){
        stack->arr[++stack->top] = num;
    }else{
        printf("Stack is Full\n");
    }
}

int pop(Stack *stack){
    int res;
    if(!isEmpty(stack)){
        res = stack->arr[stack->top];
        --stack->top;
    }else{
        printf("Stack is Empty\n");
        res = -1;
    }
    return res;
}

int peek(Stack *stack) {
    int res;
    if (!isEmpty(stack)) {
        res = stack->arr[stack->top];
    } else {
        res = -1;
    }
    return res;
}



void printStack(Stack *stack){
    for(int i = stack->top; i >= 0; i--){
        printf("%d\n",stack->arr[i]); // this is not the correct implementation, technically we should pop the stack each time to travel to thre previous element
    }
}


int main(int argc, char const *argv[])
{

    int size;
    scanf("%d",&size);
    Stack stack;
    init(&stack,size);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    printStack(&stack);
    return 0;
}
