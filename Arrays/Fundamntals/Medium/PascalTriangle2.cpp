#include <iostream>
#include <vector>

std::vector<int> pascalTriangle2(int n) {
  std::vector<int> arr(n);

  arr[0] = 1;
  long long ans = 1; // Use long long for intermediate calc
  for (int i = 1; i < n; i++) {
    ans = (ans * (n - i)) / i;
    arr[i] = (int)ans;
  }

  if (n > 0)
    arr[n - 1] = 1;

  return arr;
}

int main() {
  int n = 5;
  std::vector<int> arr = pascalTriangle2(n);

  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
