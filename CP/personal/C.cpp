#include <iostream>

void sortArray(int* nums, int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        while (nums[left] == 1 && left < right) {
            left++;
        }
        
        while (nums[right] == 0 && left < right) {
            right--;
        }
        
        if (left < right) {
            std::swap(nums[left], nums[right]);
        }
    }
}

int main() {
    // Test the sortArray function
    int nums[] = {1, 0, 1, 0, 1, 0};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    sortArray(nums, size);
    
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    
    return 0;
}
