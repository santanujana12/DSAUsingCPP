#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> &arr) {
  int n = arr.size();

  // Idea is to repeatedly swap the adjacent elements if they are in wrong order
  // Largest element will be bubbled to the end of the array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

int main() {
  // Adding main for testing purposes, absent in original file likely due to
  // being a library class or snippet
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  bubbleSort(arr);
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
