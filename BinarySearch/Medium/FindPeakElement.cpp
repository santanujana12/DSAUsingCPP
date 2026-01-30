#include <iostream>
#include <vector>

int findPeakElement(std::vector<int> &nums) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] < nums[mid + 1]) {
      // peak on the right
      l = mid + 1;
    } else {
      // peak on the left or mid
      r = mid;
    }
  }
  return l;
}

int main() {
  // Hardcoded for C++ instead of Scanner
  std::vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
  std::cout << findPeakElement(arr) << std::endl;
  return 0;
}
