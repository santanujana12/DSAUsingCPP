#include <iostream>
#include <vector>

int findMin(std::vector<int> &arr) {
  int start = 0, end = arr.size() - 1;
  while (start < end) {
    int mid = start + (end - start) / 2;

    if (arr[mid] > arr[end]) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return arr[start];
}

int main() {
  std::vector<int> nums = {90, -87, -78, -65, -49, -29, -28, -23, -2, 7,
                           12, 14,  24,  40,  46,  55,  76,  77,  80, 83};
  std::cout << findMin(nums) << std::endl;
  return 0;
}
