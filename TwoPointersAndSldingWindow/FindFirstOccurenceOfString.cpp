#include <iostream>
#include <string>
#include <vector>


int strStr(std::string haystack, std::string needle) {
  int m = needle.length();
  int n = haystack.length();

  if (m == 0) {
    return 0;
  }

  // Step 1: Build LPS
  std::vector<int> lps(m);
  int i = 0, j = 1;

  while (j < m) {
    if (needle[i] == needle[j]) {
      lps[j] = i + 1;
      i++;
      j++;
    } else {
      if (i == 0) {
        lps[j] = 0;
        j++;
      } else {
        i = lps[i - 1];
      }
    }
  }

  // Step 2: Search
  i = 0;
  j = 0;
  while (i < n) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
    } else {
      if (j == 0) {
        i++;
      } else {
        j = lps[j - 1];
      }
    }
    if (j == m) {
      return i - j;
    }
  }

  return -1;
}

int main() {
  std::string a = "sadbutsad";
  std::string b = "sad";
  std::cout << strStr(a, b) << std::endl;
  return 0;
}
