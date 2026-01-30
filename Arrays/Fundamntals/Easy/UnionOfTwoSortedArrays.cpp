#include <iostream>
#include <set>
#include <vector>


// Avoid conflict with std::union keyword by naming function unionArrays
std::vector<int> unionArrays(std::vector<int> &arr1, std::vector<int> &arr2) {
  std::set<int> ts;

  for (int i = 0; i < arr1.size(); i++) {
    ts.insert(arr1[i]);
  }

  for (int i = 0; i < arr2.size(); i++) {
    ts.insert(arr2[i]);
  }

  // Convert set back to vector
  std::vector<int> result(ts.begin(), ts.end());
  return result;
}

int main() {
  std::vector<int> arr1 = {1, 3, 4, 5, 7};
  std::vector<int> arr2 = {2, 3, 5, 6};

  std::vector<int> result = unionArrays(arr1, arr2);

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
