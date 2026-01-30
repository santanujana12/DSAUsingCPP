#include <deque>
#include <iostream>
#include <vector>


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
  int i = 0, j = 0, n = nums.size();
  std::vector<int> res;
  std::deque<int> maxQ;

  while (j < n) {
    // Remove elements smaller than current from the back
    while (!maxQ.empty() && maxQ.back() < nums[j]) {
      maxQ.pop_back();
    }
    maxQ.push_back(nums[j]);

    // When window size reaches k
    if (j >= k - 1) {
      res.push_back(maxQ.front());

      // Remove outgoing element from front if needed
      if (maxQ.front() == nums[i]) {
        maxQ.pop_front();
      }
      i++;
    }
    j++;
  }
  return res;
}

int main() {
  std::vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  std::vector<int> result = maxSlidingWindow(arr, k);

  for (int val : result) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
  return 0;
}
