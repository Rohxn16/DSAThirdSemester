#include <iostream>

using namespace std;

void arrayToNumber(int arr[], int size){
    // fucntion to convert an array to a number

    int final_value = 0;
    
    // iterating every line until the last and adding the next number to its end
    for(int i = 0; i < size; i++){
        final_value = (final_value*10)+i;
    }

    cout << final_value <<endl;
}

int main(int argc, char const *argv[])
{
    // main method
    int arr[] = {1,2,3,4,5};
    int n = 5;
    arrayToNumber(arr,n); // function call
    return 0;
}
