#include <iostream>
using namespace std;

// finding number by implementing binary search as given array is sorted
int findNum(int a[], int size, int target) {
    int left = 0;
    int right = size - 1;

    // running loop whle left pointer is less than or equals right pointer
    while (left <= right) {
        int mid = left + (right - left) / 2; //calculating mid elemeng

        if (a[mid] == target) {
            return mid; // if mid is key
        } else if (a[mid] < target) { // moving right to one element before mid in case of mid element being less than target
            right = mid - 1;
        } else { // moving left to 1 element after mid in case of mid element being more than target
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int result = findNum(arr, size, target);
    cout << result << endl;

    delete[] arr;
    return 0;
}
