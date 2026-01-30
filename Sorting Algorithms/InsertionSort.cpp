#include <iostream>
#include <vector>

// Idea is to insert the element at the correct position in the sorted array
// Front part of the array will always be sorted
std::vector<int> insertionSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
  return arr;
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::vector<int> sortedArr = insertionSort(arr);
  for (int i = 0; i < sortedArr.size(); i++) {
    std::cout << sortedArr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
