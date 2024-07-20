#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
    int start;
    int end;
}Queue;

void init(Queue *queue, int size){
    queue->arr = (int*)malloc(size * sizeof(int));
    queue->size = size;
    queue->start = queue->end = -1;
}

bool isEmpty(Queue *queue){
    if((queue->start == -1 && queue->end == -1)|| queue->start > queue->end) return true;
    else return false;
}

bool isFull(Queue* queue){
    if(queue->end==queue->size-1)return true;
    else return false;
}

void push(Queue *queue,  int num){
    if(isFull(queue)){
        printf("The queue is full, element can not be inserted\n");       
    }
    else if(isEmpty(queue)){
        queue->start = 0;
        queue->end = 0;
        queue->arr[queue->end] = num;
        printf("%d inserted at index %d",num,queue->end);
    }else{
        queue->arr[++queue->end] = num;
        printf("%d inserted at index %d",num,queue->end);
    }
}

int pop(Queue *queue){
    int res;
    if(!isEmpty(queue)){
        res = queue->start;
        queue->start++;
    }if(queue->start >=queue->end){ // this is a failsafe to reset the start and end elements of the queue
        queue->start = -1;
        queue->end = -1;
    }
    else{
        res = -1;
    }
    return res;
} 

void printQueue(Queue *queue){
    for(int i = queue->start; i <= queue->end; i++){
        printf("%d -> ",queue->arr[i]);
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
