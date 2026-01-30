#include <iostream>
#include <vector>

// Reverse algorithm
void reverse(std::vector<int> &nums, int start, int end) {
  while (start < end) {
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
}

/**
 * Rotate an array of size n by k places.
 * This algorithm first reverses the first k elements of the array, then
 * reverses the remaining n-k elements of the array, and finally reverses
 * the whole array. This results in a rotation of the array by k places.
 * Time complexity is O(n) and space complexity is O(1)
 */
void rotate(std::vector<int> &nums, int k, int n) {
  k = k % n;

  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
  reverse(nums, 0, n - 1);
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4;

  rotate(arr, k, arr.size());

  for (const auto &items : arr) {
    std::cout << items << " ";
  }
  std::cout << std::endl;
  return 0;
}
