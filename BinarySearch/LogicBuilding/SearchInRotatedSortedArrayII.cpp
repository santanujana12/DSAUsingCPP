#include <iostream>
#include <vector>

bool searchInARotatedSortedArrayII(std::vector<int> &arr, int k) {

  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == k) {
      return true;
    }
    if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
      start++;
      end--;
    } else if (arr[mid] >= arr[start]) {
      if (arr[mid] > k && k >= arr[start]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else {
      if (arr[mid] < k && k <= arr[end]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  return false;
}

int main() {
  std::vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6, 10};
  int k = 1;
  std::cout << std::boolalpha << searchInARotatedSortedArrayII(arr, k)
            << std::endl;
  return 0;
}
