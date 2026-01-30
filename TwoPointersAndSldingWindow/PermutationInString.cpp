#include <iostream>
#include <string>
#include <unordered_map>

bool checkInclusion(std::string s1, std::string s2) {
  int m = s1.length();
  int n = s2.length();
  int i = 0, j = m - 1;

  std::unordered_map<char, int> freq1;

  for (int idx = 0; idx < m; idx++) {
    char ch = s1[idx];
    freq1[ch]++;
  }

  while (j < n) {
    std::unordered_map<char, int> freq2;
    int k = i;

    while (k <= j) {
      char ch = s2[k];
      freq2[ch]++;
      k++;
    }

    if (freq2 == freq1) {
      return true;
    } else {
      i++;
      j++;
    }
  }

  return false;
}

int main() {
  std::string s1 = "ab";
  std::string s2 = "eidbaooo";
  std::cout << std::boolalpha << checkInclusion(s1, s2) << std::endl;
  return 0;
}
