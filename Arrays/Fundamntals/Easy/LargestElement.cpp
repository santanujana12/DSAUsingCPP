#include <climits>
#include <iostream>
#include <vector>


int largestElement(std::vector<int> &arr) {
  int max = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  std::vector<int> arr = {3, 3, 0, 99, -40};

  int largest = largestElement(arr);
  std::cout << largest << std::endl;
  return 0;
}
