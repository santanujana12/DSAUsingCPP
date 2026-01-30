#include <iostream>

int mySqrt(int x) {
  if (x < 2) {
    return x;
  }

  long long left = 2; // Use long long
  long long right = x / 2;

  while (left <= right) {
    long long mid = left + (right - left) / 2;
    long long product = mid * mid;

    if (product == x) {
      return (int)mid;
    } else if (product > x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return (int)right;
}

int main() {
  int x = 8;
  int result = mySqrt(x);
  std::cout << "The integer square root of " << x << " is: " << result
            << std::endl;
  return 0;
}
