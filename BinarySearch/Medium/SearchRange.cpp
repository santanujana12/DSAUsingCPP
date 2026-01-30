#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int> &arr, int target) {
  std::vector<int> result(2);
  int l = 0, r = arr.size() - 1;
  int start = -1, end = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (arr[mid] == target) {
      int i = mid, j = mid;
      // O(n) worst case degradation, but faithfully converting the provided
      // Java logic
      while (i >= 0 && arr[i] == target) {
        i--;
      }
      while (j < arr.size() && arr[j] == target) {
        j++;
      }
      start = i + 1;
      end = j - 1;
      break;
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  result[0] = start;
  result[1] = end;
  return result;
}

int main() {
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  std::vector<int> result = searchRange(nums, target);
  std::cout << result[0] << " " << result[1] << std::endl;
  return 0;
}
