#include <algorithm>
#include <iostream>
#include <vector>


std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> res;
  std::sort(nums.begin(), nums.end());
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue; // skip duplicates
    }

    int j = i + 1, k = n - 1;

    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];

      if (sum == 0) {
        res.push_back({nums[i], nums[j], nums[k]});

        while (j < k && nums[j] == nums[j + 1]) {
          j++;
        }
        while (j < k && nums[k] == nums[k - 1]) {
          k--;
        }

        j++;
        k--;
      } else if (sum > 0) {
        k--;
      } else {
        j++;
      }
    }
  }
  return res;
}

int main() {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> result = threeSum(nums);

  for (const auto &triplet : result) {
    for (int val : triplet) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
