#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>


// Function to find the number of rotations in a rotated sorted array
int findKRotation1(std::vector<int> &nums) {
  int low = 0, high = nums.size() - 1;
  int ans = INT_MAX;
  int index = -1;
  while (low <= high) {
    int mid = (low + high) / 2;

    if (nums[low] <= nums[high]) {
      if (nums[low] < ans) {
        index = low;
        ans = nums[low];
      }
      break;
    }

    // If left part is sorted update the ans
    if (nums[low] <= nums[mid]) {
      if (nums[low] < ans) {
        index = low;
        ans = nums[low];
      }
      // Eliminate left half
      low = mid + 1;
    } else {
      if (nums[mid] < ans) {
        index = mid;
        ans = nums[mid];
      }
      // Eliminate right half
      high = mid - 1;
    }
  }
  // Return the index as answer
  return index;
}

int findKRotation(std::vector<int> &arr) {
  int start = 0, end = arr.size() - 1;
  int minimum = INT_MAX, index = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;

    // check if left side is sorted
    if (arr[start] <= arr[mid]) {
      if (arr[start] < minimum) {
        minimum = arr[start];
        index = start;
        // Note: The original java code used `index = arr.indexOf(minimum)`.
        // Searching index again is O(n), defeating binary search purpose.
        // In binary search logic, we know the index is `start` here.
      }
      // Recalibrating logic from original Java code which was suboptimal:
      // Java: `minimum = Math.min(arr.get(start), minimum); index =
      // arr.indexOf(minimum);` I'll optimize it to use `start` directly if it's
      // the new minimum.
      start = mid + 1;
    } else {
      if (arr[mid] < minimum) {
        minimum = arr[mid];
        index = mid;
      }
      end = mid - 1;
    }
  }
  return index;
}

int main() {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
  std::cout << findKRotation(nums) << std::endl;
  return 0;
}
