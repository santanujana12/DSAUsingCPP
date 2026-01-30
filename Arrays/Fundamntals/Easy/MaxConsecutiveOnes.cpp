#include <algorithm>
#include <iostream>
#include <vector>


int findMaxConsecutiveOnes(std::vector<int> &nums) {

  int maxCount = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      count++;
      maxCount = std::max(maxCount, count);
    } else {
      count = 0;
    }
  }
  return maxCount;
}

int main() {
  std::vector<int> arr = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1,
                          1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                          1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0,
                          0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

  std::cout << findMaxConsecutiveOnes(arr) << std::endl;
  return 0;
}
