#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>


int characterReplacement(std::string s, int k) {
  std::unordered_map<char, int> freq;
  int maxCharReplacement = 0;
  int i = 0, n = s.length(), maxFreqCount = 0;

  for (int j = 0; j < n; j++) {
    char ch = s[j];
    freq[ch]++;
    maxFreqCount = std::max(maxFreqCount, freq[ch]);

    // Shrink window
    while ((j - i + 1) - maxFreqCount > k) {
      char leftChar = s[i];
      freq[leftChar]--;
      i++;
      // Note: maxFreqCount is not updated here, which is a known
      // optimization/valid logic for this problem. Even if maxFreqCount
      // decreases, the window size condition still holds correctly for finding
      // the MAX window.
    }

    maxCharReplacement = std::max(maxCharReplacement, j - i + 1);
  }

  return maxCharReplacement;
}

int main() {
  std::string s = "ABAB";
  int k = 2;
  std::cout << characterReplacement(s, k) << std::endl;
  return 0;
}
