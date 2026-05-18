#include <iostream>

    // Given a sorted array, remove the duplicates in-place so that each element appears only once
    // and return the new length. Do not use extra space.

int removeDuplicatesAndReturnNewLength (int* arr, int n) {
        if (n == 0) return 0;
        
        int slow = 0;
    
        for (int fast = 1; fast < n; fast++) {
            if (arr[fast] != arr[slow]) {
                slow++;
                arr[slow] = arr[fast];
            }
        }
    
        return slow + 1;
    }

int main (){

    int arr[] = {0, 0, 1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // new array = {0,1,2,3,2,2,3} but only cout to new length
    // so it 0 1 2 3

    int newLen = removeDuplicatesAndReturnNewLength(arr, n);

    std::cout << "New length: " << newLen << '\n';
    for (int i = 0; i < newLen; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}