#include <iostream>
#include <vector>

void moveZeroesToEnd(std::vector<int> &arr) {
  int index = 0;
  int n = arr.size();

  // checking if arr[i]!=0 then swap first index which is present at index 0 ->
  // n This fills all the non-zero element first and then loop from index to n
  // to fill the zeroes
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[index] = arr[i];
      index++;
    }
  }

  for (int i = index; i < n; i++) {
    arr[i] = 0;
  }
}

int main() {
  std::vector<int> arr = {0, 0, 0, 1, 3, -2};

  moveZeroesToEnd(arr);

  for (const auto &item : arr) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
