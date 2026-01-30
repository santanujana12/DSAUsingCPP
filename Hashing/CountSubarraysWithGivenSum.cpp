#include <iostream>
#include <unordered_map>
#include <vector>


int countSubArraysWithGivenSum(std::vector<int> &arr, int k) {
  std::unordered_map<int, int> prefixSumMap;

  prefixSumMap[0] = 1;

  int count = 0;
  int prefixSum = 0;

  for (int i = 0; i < arr.size(); i++) {
    prefixSum += arr[i];

    if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
      count += prefixSumMap[prefixSum - k];
    }
    // Increment value of prefixSum if exists else initialize the same with 0
    prefixSumMap[prefixSum]++;
  }

  return count;
}

int main() {
  std::vector<int> arr = {1, 2, 3};
  int k = 3;
  std::cout << countSubArraysWithGivenSum(arr, k) << std::endl;
  return 0;
}
