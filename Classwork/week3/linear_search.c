#include <stdio.h>

int main(void){
    int count = 0;
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements of the array:\n");
    for(int i = 0 ; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key element to be searched:\n");
    int key;
    scanf("%d",&key);

    for(int i = 0 ; i < n; i++){
        // scanf("%d",&arr[i]);
        if(arr[i] == key){
            printf("Key found at index : %d\n",i);
            count++;
        }
    }
    if(count == 0) printf("Element not found\n");
    else printf("The number of occurences of the key element %d is %d times\n",key,count);
}