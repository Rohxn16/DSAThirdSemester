#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int n, int key){
    int start = 0;
    int end = n;
    int mid = (start + end) / 2;
    

    while(start <= end){
    
        mid = (start + end) / 2;
    
        if(arr[mid] == key) return mid;
        else if(key > arr[mid]){
            // shift to right
            start = mid+1;
        }else{
            end = mid-1;
        }

    }

return -1;

}

int main(){
    
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    int res = binarySearch(arr,n,key);
    if(res == -1) printf("Not Found\n");
    else printf("Element found at index %d\n",res);

}
