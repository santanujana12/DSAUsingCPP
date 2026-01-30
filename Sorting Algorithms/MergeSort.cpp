#include <iostream>
#include <vector>

// This function is used to merge two sorted arrays
void merge(std::vector<int> &arr, int left, int mid, int right) {
  // Temporary array to store sorted elements
  std::vector<int> temp;
  int j = left;
  int k = mid + 1;

  // Loop until one of the subarrays is exhausted
  while (j <= mid && k <= right) {
    if (arr[j] <= arr[k]) {
      temp.push_back(arr[j]);
      j++;
    } else {
      temp.push_back(arr[k]);
      k++;
    }
  }

  // Push remaining elements
  while (j <= mid) {
    temp.push_back(arr[j]);
    j++;
  }
  while (k <= right) {
    temp.push_back(arr[k]);
    k++;
  }

  // Copying elements to original array
  for (int i = left; i <= right; i++) {
    /*
     * i-left returns the index of the copied array that means suppose left = 3
     * now i=3 and 3-3=0 hence at main index 3 the value of 0th index of the
     * temporary array will be copied
     */
    arr[i] = temp[i - left];
  }
}

void mergeSortHelper(std::vector<int> &arr, int start, int end) {
  if (start >= end) {
    return;
  }
  // Find middle index
  // Main magic happens in finding mid element which divides the array
  int mid = (start + end) / 2;
  // Recursively sort left half
  mergeSortHelper(arr, start, mid);
  // Recursively sort right half
  mergeSortHelper(arr, mid + 1, end);
  // Merge the two halves
  merge(arr, start, mid, end);
}

std::vector<int> mergeSort(std::vector<int> &arr) {
  if (arr.size() <= 1) {
    return arr;
  }
  mergeSortHelper(arr, 0, arr.size() - 1);
  return arr;
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::vector<int> sortedArr = mergeSort(arr);
  for (int i = 0; i < sortedArr.size(); i++) {
    std::cout << sortedArr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
