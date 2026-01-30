#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>


int lengthOfLongestSubstring(std::string s) {
  int maxLength = 0;
  int n = s.length();
  int i = 0;

  std::unordered_map<char, int> substring;

  for (int j = 0; j < n; j++) {
    char ch = s[j];

    if (substring.find(ch) != substring.end() && substring[ch] >= i) {
      i = substring[ch] + 1;
    }

    substring[ch] = j;
    maxLength = std::max(maxLength, j - i + 1);
  }

  return maxLength;
}

int main() {
  std::string s = "abcabcbb";
  std::cout << lengthOfLongestSubstring(s) << std::endl;
  return 0;
}
