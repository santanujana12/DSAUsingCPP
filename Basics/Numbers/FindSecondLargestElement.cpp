#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::vector<int> arr = {0, 3, 5, 2, 7, 9};
    int n = arr.size();
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    std::cout << second_largest << std::endl;
    return 0;
}
