// Q. implement bubble sort using C with user defined function.


#include <stdio.h>

void bubbleSort(int *arr, int n){
    // bubble sort the array
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
}

// int arr[] = new int[4];