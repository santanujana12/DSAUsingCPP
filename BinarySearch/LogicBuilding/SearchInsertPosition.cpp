#include <iostream>
#include <vector>

int searchInsertPosition(std::vector<int> &arr, int target) {
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return start;
}

int main() {
  std::vector<int> arr = {3, 5, 6, 8, 9, 11};
  int target = 4;
  std::cout << searchInsertPosition(arr, target) << std::endl;
  return 0;
}
