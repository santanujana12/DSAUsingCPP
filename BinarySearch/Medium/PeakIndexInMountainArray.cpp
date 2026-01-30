#include <iostream>
#include <vector>

int peakIndexInMountainArray(std::vector<int> &arr) {
  int l = 0;
  int r = arr.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    // Check bounds for mid-1 and mid+1.
    // In mountain array, length >= 3 guaranteed usually.
    // But safe to check.
    if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] &&
        arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {0, 10, 5, 2};
  std::cout << peakIndexInMountainArray(arr) << std::endl;
  return 0;
}
