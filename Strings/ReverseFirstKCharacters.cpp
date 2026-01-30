#include <algorithm>
#include <iostream>
#include <string>


std::string reverseString(std::string s, int k) {
  int n = s.length();
  for (int i = 0; i < n; i += (2 * k)) {
    int lenToReverse = std::min(k, n - i);
    // Reverse substring from i to i + lenToReverse
    std::reverse(s.begin() + i, s.begin() + i + lenToReverse);
  }
  return s;
}

int main() {
  std::string s = "abcdefghij";
  int k = 2;
  std::string reversedString = reverseString(s, k);
  std::cout << reversedString << std::endl;
  return 0;
}
