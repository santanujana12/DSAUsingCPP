#include <iostream>
#include <unordered_map>
#include <vector>


std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                    std::vector<int> &nums2) {
  std::unordered_map<int, int> nextGreater;
  std::vector<int> result;

  // Brute force logic from Java to find next greater in nums2
  for (int i = 0; i < nums2.size();
       i++) { // Corrected loop condition from Java code that was partially
              // correct/inefficient
              // Java code: for (int i = 0; i < nums2.size() - 1; i++) ...
              // Wait, if last element has no greater, it's not put in map?
              // Map defaults?
              // Java: `if (!nextGreater.containsKey(num)) result.add(-1);`
    for (int j = i + 1; j < nums2.size(); j++) {
      if (nums2[i] < nums2[j]) {
        nextGreater[nums2[i]] = nums2[j];
        break;
      }
    }
  }

  for (int num : nums1) {
    if (nextGreater.find(num) == nextGreater.end()) {
      result.push_back(-1);
    } else {
      result.push_back(nextGreater[num]);
    }
  }

  return result;
}

int main() {
  std::vector<int> nums1 = {4, 1, 2};
  std::vector<int> nums2 = {1, 3, 4, 2};
  std::vector<int> result = nextGreaterElement(nums1, nums2);

  // Output the result
  for (int res : result) {
    std::cout << res << std::endl;
  }
  return 0;
}
