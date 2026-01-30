#include <iostream>
#include <vector>

// Unoptimized solution
std::vector<int> rearrangeArray(std::vector<int> &nums) {
  std::vector<int> positiveNumbers;
  std::vector<int> negativeNumbers;
  std::vector<int> result(nums.size());

  // Separate positive and negative numbers
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      positiveNumbers.push_back(nums[i]);
    } else {
      negativeNumbers.push_back(nums[i]);
    }
  }

  int i = 0, j = 0;
  int k = 0;

  // Alternate adding positive and negative numbers
  while (i < positiveNumbers.size() && j < negativeNumbers.size()) {
    result[k++] = positiveNumbers[i++];
    result[k++] = negativeNumbers[j++];
  }

  // If there are remaining positive numbers
  while (i < positiveNumbers.size()) {
    result[k++] = positiveNumbers[i++];
  }

  // If there are remaining negative numbers
  while (j < negativeNumbers.size()) {
    result[k++] = negativeNumbers[j++];
  }

  return result;
}

// Optimal solution
std::vector<int> rearrangeArrayOptimal(std::vector<int> &nums) {
  std::vector<int> result(nums.size());
  int postiveIndex = 0,
      negativeIndex = 1; // since negativeIndex will always be in Odd position

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      result[postiveIndex] = nums[i];
      postiveIndex += 2; // This gives space to negative numbers
    } else {
      result[negativeIndex] = nums[i];
      negativeIndex += 2;
    }
  }

  return result;
}

int main() {
  std::vector<int> arr = {2, 4, 5, -1, -3, -4};
  std::vector<int> result = rearrangeArrayOptimal(arr);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
