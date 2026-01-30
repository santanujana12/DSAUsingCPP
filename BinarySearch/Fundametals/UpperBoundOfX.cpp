#include <algorithm>
#include <iostream>
#include <vector>


int findUpperBound(std::vector<int> &arr, int k) {
  int start = 0, end = arr.size() - 1, minIndex = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] <= k) {
      minIndex = std::max(
          minIndex, mid); // Logic check: Normally upper bound is first element
                          // > k. Java code: if(arr[mid] <= k) {
                          // minIndex=max(minIndex, mid); start=mid+1; } This
                          // finds the LAST element <= k. return minIndex + 1.
                          // If last element <= k is at index i, then i+1 is
                          // first element > k. Yes, this is Upper Bound.
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return minIndex + 1;
}

int main() {
  std::vector<int> arr = {3, 5, 8, 15, 19};
  int k = 9;
  std::cout << findUpperBound(arr, k) << std::endl;
  return 0;
}
