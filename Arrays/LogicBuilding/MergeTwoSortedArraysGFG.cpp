#include <algorithm>
#include <iostream>
#include <vector>


void mergeArrays(std::vector<int> &a, std::vector<int> &b) {
  int pointer_a = a.size() - 1, pointer_b = 0;
  while (pointer_a >= 0 && pointer_b < b.size() &&
         a[pointer_a] > b[pointer_b]) {
    int temp = a[pointer_a];
    a[pointer_a] = b[pointer_b];
    b[pointer_b] = temp;
    pointer_a--;
    pointer_b++;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
}

int main() {
  std::vector<int> a = {2, 4, 7, 10};
  std::vector<int> b = {2, 3};
  mergeArrays(a, b);
  std::cout << "a: ";
  for (int i : a) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "b: ";
  for (int i : b) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
