#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>


int longestSubArrayHavingSumK(std::vector<int> &arr, int k) {
  std::unordered_map<int, int> prefixSumMap;
  prefixSumMap[0] = -1;
  int prefixSum = 0, maxLength = 0;

  for (int currentIndex = 0; currentIndex < arr.size(); currentIndex++) {
    prefixSum += arr[currentIndex];

    if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
      int length = currentIndex - prefixSumMap[prefixSum - k];
      maxLength = std::max(maxLength, length);
    }
    // putting every prefixSum as key and value to be currentIndex
    if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
      prefixSumMap[prefixSum] = currentIndex;
    }
  }

  return maxLength;
}

int main() {
  std::vector<int> arr = {10, 5, 2, 7, 1, 9};
  int k = 15;
  std::cout << longestSubArrayHavingSumK(arr, k) << std::endl;
  return 0;
}
