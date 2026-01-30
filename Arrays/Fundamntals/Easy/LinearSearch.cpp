#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &arr, int target) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {2, 3, 4, 5, 3};
  int key = 8;

  std::cout << linearSearch(arr, key) << std::endl;
  return 0;
}
