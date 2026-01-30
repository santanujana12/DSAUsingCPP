#include <iostream>
#include <vector>

int findFirst(std::vector<int> &arr, int target) {
  int res = -1;
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) {
      res = mid;
      end = mid - 1;
    } else if (arr[mid] >= target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return res;
}

int findLast(std::vector<int> &arr, int target) {
  int res = -1;
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) {
      res = mid;
      start = mid + 1;
    } else if (arr[mid] <= target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return res;
}

std::vector<int> searchRange(std::vector<int> &arr, int target) {
  std::vector<int> result(2);

  result[0] = findFirst(arr, target);
  result[1] = findLast(arr, target);

  return result;
}

int main() {
  std::vector<int> arr = {5, 7, 7, 8, 8, 10};
  int target = 8;
  std::vector<int> result = searchRange(arr, target);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
