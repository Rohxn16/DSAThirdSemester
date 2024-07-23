#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the key to be searched\n");
    int key;
    scanf("%d",&key);
    for(int i = 0; i  < n; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n",i);
            return 0;
        }
        
    }
printf("Element not found\n");
return 0;
}
