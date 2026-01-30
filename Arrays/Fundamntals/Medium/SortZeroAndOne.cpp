#include <iostream>
#include <vector>

// Implementation of DNF Algorithm
void sortZeroAndOne(std::vector<int> &arr) {
  int n = arr.size();

  int start = 0, mid = 0, end = n - 1;
  while (mid <= end) {
    if (arr[mid] == 0) {
      // Swap start and mid
      int temp = arr[start];
      arr[start] = arr[mid];
      arr[mid] = temp;
      start++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else if (arr[mid] == 2) {
      // Swap mid and end
      int temp = arr[end];
      arr[end] = arr[mid];
      arr[mid] = temp;
      end--;
    }
  }
}

int main() {
  std::vector<int> arr = {1, 0, 2, 1, 0};

  sortZeroAndOne(arr);

  for (int i : arr) {
    std::cout << i << std::endl;
  }
  return 0;
}
