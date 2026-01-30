#include <iostream>
#include <string>
#include <vector>


int strStr(std::string haystack, std::string needle) {
  if (needle.length() == 0)
    return 0;

  std::vector<int> lps(needle.length());

  // Build LPS array
  int i = 0, j = 1;
  while (j < needle.length()) {
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

  // KMP search
  i = 0;
  j = 0;
  while (i < haystack.length()) {
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

    if (j == needle.length()) {
      return i - j;
    }
  }

  return -1;
}

int main() {
  std::string a = "hello";
  std::string b = "ll";
  // Usually KMP or strStr tests use "hello", "ll" -> 2.
  std::cout << strStr(a, b) << std::endl;
  return 0;
}
