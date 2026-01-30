#include <algorithm>
#include <iostream>
#include <vector>


int findLowerBound(std::vector<int> &arr, int k) {
  std::sort(arr.begin(), arr.end());
  int start = 0, end = arr.size() - 1, minIndex = arr.size();
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] >= k) {
      minIndex = std::min(minIndex, mid);
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return minIndex;
}

int main() {
  std::vector<int> arr = {3, 5, 8, 15, 19};
  int k = 3;
  std::cout << findLowerBound(arr, k) << std::endl;
  return 0;
}
