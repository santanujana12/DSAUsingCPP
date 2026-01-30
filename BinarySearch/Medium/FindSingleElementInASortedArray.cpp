#include <iostream>
#include <vector>

int singleNonDuplicate(std::vector<int> &arr) {
  int l = 0;
  int r = arr.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;
    // Check bounds before accessing arr[m-1] or arr[m+1]
    // The Java code relies on specific short-circuit evaluation or bounds logic
    // that might be subtle Java: (m == 0 || arr[m] != arr[m - 1]) && (m ==
    // arr.length - 1 || arr[m] != arr[m + 1]) This is safe in C++ too as long
    // as arr.size() > 0.
    if ((m == 0 || arr[m] != arr[m - 1]) &&
        (m == arr.size() - 1 || arr[m] != arr[m + 1])) {
      return arr[m];
    } else {
      int rightLength;
      if (m > 0 && arr[m] == arr[m - 1]) {
        rightLength = r - m;
        if (rightLength % 2 == 0) {
          r = m - 2;
        } else {
          l = m + 1;
        }
      } else if (m < arr.size() - 1 && arr[m] == arr[m + 1]) {
        rightLength = r - m + 1;
        if (rightLength % 2 == 0) {
          r = m - 1;
        } else {
          l = m + 2;
        }
      }
    }
  }

  return -1; // Just in case, but ideally this should never be reached
}

int main() {
  std::vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  std::cout << singleNonDuplicate(arr) << std::endl;
  return 0;
}
