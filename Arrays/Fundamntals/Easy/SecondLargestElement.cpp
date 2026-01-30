#include <climits>
#include <iostream>
#include <vector>


int secondLargestElement(std::vector<int> &arr) {
  int largest = INT_MIN;
  int secondLargest = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if (arr[i] < largest && arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }

  return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
  std::vector<int> arr = {7, 7, 2, 2, 10, 10, 10};
  int secondLargest = secondLargestElement(arr);

  std::cout << secondLargest << std::endl;
  return 0;
}
