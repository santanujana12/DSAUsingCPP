#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {1, 6, 2, 10, 3};
  int target = 7;
  std::vector<int> result(2);

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
      }
    }
  }

  for (int i : result) {
    std::cout << i << std::endl;
  }
  return 0;
}
