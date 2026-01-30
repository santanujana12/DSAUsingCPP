#include <iostream>
#include <vector>

std::vector<int> getFloorAndCeil(std::vector<int> &arr, int x) {
  std::vector<int> result(2);

  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == x) {
      result[0] = x;
      result[1] = x;
      return result;
    } else if (arr[mid] > x) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  result[0] = (end >= 0) ? arr[end] : -1;             // floor
  result[1] = (start < arr.size()) ? arr[start] : -1; // ceil
  return result;
}

int main() {
  std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
  int x = 1;
  std::vector<int> result = getFloorAndCeil(arr, x);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
