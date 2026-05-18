#include <iostream>
#include <climits> // for INT_MAX

    // O(n) time

    // find the shortest subarray that is >= the target S
    // using 2 pointer int windwoStart, int windowEnd (in a loop)

int main() {
    int arr[] = {2, 1, 5, 2, 3, 2};
    int S = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int windowSum = 0;
    int minLength = INT_MAX;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        windowSum += arr[windowEnd]; // expand the window

        // shrink the window as small as possible while the sum ≥ S
        while (windowSum >= S) {
            minLength = std::min(minLength, windowEnd - windowStart + 1);
            windowSum -= arr[windowStart]; // shrink from the left
            windowStart++;  
        }
    }

    std::cout << (minLength == INT_MAX ? 0 : minLength) << '\n';

    return 0;
}
