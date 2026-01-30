#include <algorithm>
#include <iostream>
#include <vector>


std::vector<std::vector<int>> fourSum(std::vector<int> &arr, int target) {
  std::vector<std::vector<int>> result;

  std::sort(arr.begin(), arr.end());

  int n = arr.size();
  for (int i = 0; i < n - 3; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < n - 2; j++) {
      if (j > i + 1 && arr[j] == arr[j - 1]) {
        continue;
      }
      int k = j + 1;
      int l = n - 1;
      while (k < l) {
        // Use long long to prevent overflow
        long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
        if (sum > target) {
          l--;
        } else if (sum < target) {
          k++;
        } else {
          std::vector<int> eachRow;
          eachRow.push_back(arr[i]);
          eachRow.push_back(arr[j]);
          eachRow.push_back(arr[k]);
          eachRow.push_back(arr[l]);
          result.push_back(eachRow);
          l--;
          k++;
          while (k < l && arr[k] == arr[k - 1]) {
            k++;
          }
          while (l > k && arr[l] == arr[l + 1]) {
            l--;
          }
        }
      }
    }
  }

  return result;
}

// Driver function
int main() {
  std::vector<int> arr = {1, -2, 3, 5, 7, 9};
  int target = 7;

  std::vector<std::vector<int>> result = fourSum(arr, target);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
