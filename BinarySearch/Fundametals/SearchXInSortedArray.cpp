#include <iostream>
#include <vector>

int search(std::vector<int> &arr, int target) {
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
  return -1;
}

int main() {
  std::vector<int> arr = {-1, 0, 3, 5, 9, 12};
  int target = 6;
  std::cout << search(arr, target) << std::endl;
  return 0;
}
