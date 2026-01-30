#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>


// brute solution
int maxProfit(std::vector<int> &arr) {
  int maxProfit = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j < arr.size(); j++) {
      if (arr[j] > arr[i] && i != j) {
        int diff = std::abs(arr[i] - arr[j]);
        if (diff > maxProfit) {
          maxProfit = diff;
        }
      }
    }
  }
  return maxProfit;
}

// optimal
int maxProfitOptimal(std::vector<int> &arr) {
  if (arr.empty())
    return 0;
  int minValue = arr[0];
  int maxProfit = 0;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < minValue) {
      minValue = arr[i];
    }
    int profit = arr[i] - minValue;
    if (profit > maxProfit) {
      maxProfit = profit;
    }
  }
  return maxProfit;
}

int main() {
  // Hardcoded input for demonstration as C++ usually doesn't do interactive
  // input in these snippets
  std::vector<int> arr = {7, 1, 5, 3, 6, 4};
  std::cout << maxProfitOptimal(arr) << std::endl;
  return 0;
}
