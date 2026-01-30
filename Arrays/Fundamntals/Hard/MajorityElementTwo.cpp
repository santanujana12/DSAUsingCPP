#include <iostream>
#include <vector>

std::vector<int> majorityElementTwo(std::vector<int> &arr) {
  std::vector<int> result;

  int element1 = 0, count1 = 0, element2 = 0, count2 = 0;
  for (int i = 0; i < arr.size(); i++) {
    // Making sure element 1 and element 2 are distinct elements
    if (count1 == 0 && element2 != arr[i]) {
      element1 = arr[i];
      count1++;
    } else if (count2 == 0 && element1 != arr[i]) {
      element2 = arr[i];
      count2++;
    } else if (element1 == arr[i]) {
      count1++;
    } else if (element2 == arr[i]) {
      count2++;
    } else {
      count1--;
      count2--;
    }
  }

  count1 = 0;
  count2 = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == element1) {
      count1++;
    } else if (arr[i] == element2) {
      count2++;
    }
  }

  // Note: arr.size()/3 is integer division
  if (count1 > (int)(arr.size() / 3)) {
    result.push_back(element1);
  }
  if (count2 > (int)(arr.size() / 3)) {
    result.push_back(element2);
  }

  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 1, 1, 3, 2};
  std::vector<int> result = majorityElementTwo(nums);

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
