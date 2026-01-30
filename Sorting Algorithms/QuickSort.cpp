#include <iostream>
#include <vector>

void swap(std::vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

/**
 * This function finds the partition index for the given array and given
 * start and end indices. The partition index is the index where the
 * partitioning element (pivot) is placed such that all elements to the
 * left of it are smaller and all elements to the right are larger. The
 * function takes the array and the start and end indices as parameters and
 * returns the partition index. The function also modifies the given array
 * by rearranging the elements such that the pivot is at the correct
 * position and all elements to the left of it are smaller and all elements
 * to the right are larger.
 * @param arr the array to be partitioned
 * @param start the start index
 * @param end the end index
 * @return the partition index
 */
int findPartition(std::vector<int> &arr, int start, int end) {
  int i = start - 1;
  int pivot = arr[end];

  for (int j = start; j <= end - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr, i, j);
    }
  }

  swap(arr, i + 1, end);
  return i + 1;
}

/**
 * This function is a recursive helper function for performing QuickSort on the
 * given array. It takes the array and the start and end indices as parameters
 * and sorts the elements in-place between these indices using the QuickSort
 * algorithm. The function divides the array into smaller subarrays based on the
 * partition index and recursively sorts the left and right subarrays.
 *
 * @param arr the array to be sorted
 * @param start the start index of the subarray to be sorted
 * @param end the end index of the subarray to be sorted
 */

void quickSortHelper(std::vector<int> &arr, int start, int end) {
  if (start >= end) {
    return;
  }
  int partition = findPartition(arr, start, end);
  quickSortHelper(arr, start, partition - 1);
  quickSortHelper(arr, partition + 1, end);
}

std::vector<int> quickSort(std::vector<int> &arr, int start, int end) {
  if (start >= end) {
    return arr;
  }
  quickSortHelper(arr, start, end);
  return arr;
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::vector<int> sortedArr = quickSort(arr, 0, arr.size() - 1);
  for (int i = 0; i < sortedArr.size(); i++) {
    std::cout << sortedArr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
