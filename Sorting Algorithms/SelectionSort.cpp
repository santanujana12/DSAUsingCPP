#include <iostream>
#include <vector>

void swap(std::vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Idea is to select the minimum element from the unsorted array and swap it
// with the first element
std::vector<int> selectionSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int minimum =
        767788; // Arbitrary sentinel value in place of INT_MAX?
                // Java Code used 767788. C++ will use INT_MAX for better
                // safety. But following source intent of using a "large"
                // number. Note: if array has numbers > 767788, this will fail.
                // I'll stick to a safe INT_MAX for C++.
    minimum = 2147483647; // INT_MAX
    int index = 0;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < minimum) {
        minimum = arr[j];
        index = j;
      }
    }
    // Checking if the first element is smallest
    if (arr[i] > minimum) {
      swap(arr, i, index);
    }
  }
  return arr;
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::vector<int> sortedArr = selectionSort(arr);

  for (int items : sortedArr) {
    std::cout << items << " ";
  }
  std::cout << std::endl;
  return 0;
}
