#include <iostream>
using namespace std;

// function to swap i and n -ith element of the array when the sum is not divisible by 5
void specialSwap(int arr[], int n){
    for(int i = 0; i < n/2; i++){ // traversing the array till middle
        int a = arr[i];
        int b = arr[n-i-1];
        
        if((a+b) % 5 == 0) continue; // checking for divisibility
        else{ // swapping if not divisible
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
    }

    // printing the new array
    cout << "The new array is : \n";
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
}

int main(int argc, char const *argv[])
{ // main method
    int arr[] = {2,5,9,5,11,8,3}; 
    int n = 7;
    specialSwap(arr,n); //calling the funciton
    return 0;
}
