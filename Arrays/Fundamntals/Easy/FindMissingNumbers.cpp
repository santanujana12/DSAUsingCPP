#include <iostream>
#include <vector>

// TC: O(n)
// SC: O(n)
int findMissingNumbers(std::vector<int>& arr, int n) {
    // storing all the values in the frequency array
    // Java was int freq[] = new int[n+1];
    std::vector<int> freq(n + 1, 0);

    for(int i = 0; i < n; i++) {
        // Ensure index is within bounds
        if (arr[i] <= n) {
            freq[arr[i]]++;
        }
    }

    for(int i = 0; i <= n; i++) {
        if(freq[i] == 0) {
            return i;
        }
    }

    return -1;
}

// Optimal way
int findMissingNumberUsingAP(std::vector<int>& arr, int n) {
    int sum1 = (n * (n + 1)) / 2;
    int sum2 = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum2 += arr[i];
    }

    return sum1 - sum2;
}

int main() {
    int n = 6;
    std::vector<int> arr = {1, 3, 6, 4, 2, 5};
    
    // Check missing numbers
    std::cout << findMissingNumbers(arr, n) << std::endl;
    return 0;
}
