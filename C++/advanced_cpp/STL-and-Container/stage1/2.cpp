#include <iostream>
#include <climits>

    // O(n^2) time

    // find the shortest subarray that is >= the target S
    // using 1 pointer (arr[i])

int main (){

    int arr[] = {2, 1, 5, 2, 3, 2};
    int S = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int minLength = INT_MAX;
   
    /*

    int* windowEnd = nullptr;
    int* windowStart = arr;
    int windowSum,currentMin = 0;

    for (int i = 0; i < n; i++){
        windowEnd = windowStart;
        for (int j = 0; j < n; j++){
                windowSum += *(windowEnd + j);
                currentMin = j + 1;
                if (windowSum >= S){
                    continue;
                }
            }
        windowStart++;
        minLength = std::min(minLength,currentMin);
    }

    */

    for (int start = 0; start < n; start++) {
        int windowSum = 0;

        for (int end = start; end < n; end++) {
            windowSum += arr[end];

            if (windowSum >= S) {
                int currentLength = end - start + 1;
                minLength = std::min(minLength, currentLength);
                break; // ✅ No need to check longer windows starting from same point
                       // break will exit 1 loop. continue will skip the current iteration.
            }
        }
    }

    std::cout << (minLength == INT_MAX ? 0 : minLength);

    return 0;
}