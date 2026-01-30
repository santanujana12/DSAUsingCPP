#include <climits>
#include <iostream>
#include <vector>


int maxSubarraySum(std::vector<int> &arr) {
  int maxResult = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    int sum = 0;
    for (int j = i; j < arr.size(); j++) {
      sum += arr[j];
      if (sum > maxResult) {
        maxResult = sum;
      }
    }
  }

  return maxResult;
}

// Resolving the same with More optimal algorithm Kadene's algorithm
int KadeneAlgorithm(std::vector<int> &arr) {
  int maxResult = INT_MIN;
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    // add current element to the sum
    sum += arr[i];
    // check if maxResult is less than sum then update maxResult with sum
    if (sum > maxResult) {
      maxResult = sum;
    }
    // reset sum to 0 if sum is found to be negative
    if (sum < 0) {
      sum = 0;
    }
  }

  return maxResult;
}

int main() {
  std::vector<int> arr = {-2, -3, -7, -2, -10, -4};
  std::cout << KadeneAlgorithm(arr) << std::endl;
  return 0;
}
