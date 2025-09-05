#include <iostream>

    // find the maximum sum of a subarray of length k
    // used sliding window technique and keep updating the maxSum value

void reverseArray(int* arr, int size){
    int temp = 0;
    for (int i = 0; i < size/2; i++){
        temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
};

int main (){

    int arr[] = {2,1,5,1,3,2};
    int k = 3;
    int windowSum = 0;
    int n = sizeof(arr) / sizeof(arr[0]); // always good to do this for safety 
    int* pArr = arr;

    for (int i = 0; i < k; i++){
        windowSum += arr[i];
    }
    int maxSum = windowSum;

    for (int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        maxSum = std::max(windowSum,maxSum);
    }
    
    std::cout << maxSum << '\n';

    reverseArray(pArr,6);

    for (int i = 0; i < n; i++){
        std::cout << arr[i] << '\n';
    }

    return 0;
}