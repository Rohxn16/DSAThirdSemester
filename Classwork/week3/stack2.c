#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int *stack = (int*)malloc(n*sizeof(int));

    //implement stack ops
    int top = -1;
    int choice;
    int data;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(top == n-1){
                    printf("Stack is full\n");
                }else{
                    printf("Enter data\n");
                    scanf("%d",&data);
                    stack[++top] = data;
                }
                break;
            case 2:
                if(top == -1){
                    printf("Stack is empty\n");
                }else{
                    printf("Popped element is %d\n",stack[top--]);
                }
                break;
            case 3:
                if(top == -1){
                    printf("Stack is empty\n");
                }else{
                    for(int i = 0; i <= top; i++){
                        printf("%d ",stack[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
        }
    }
}