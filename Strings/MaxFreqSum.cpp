#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>


int maxFreqSum(std::string s) {
  int maxVowelCount = 0;
  int maxConsonantCount = 0;

  std::unordered_map<char, int> vowelCount;
  std::unordered_map<char, int> consonantCount;

  for (int i = 0; i < s.length(); i++) {
    char currentChar = s[i];
    if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
        currentChar == 'o' || currentChar == 'u') {
      vowelCount[currentChar]++;
    } else {
      consonantCount[currentChar]++;
    }
  }

  for (auto const &[key, val] : vowelCount) {
    maxVowelCount = std::max(maxVowelCount, val);
  }

  for (auto const &[key, val] : consonantCount) {
    maxConsonantCount = std::max(maxConsonantCount, val);
  }

  return maxConsonantCount + maxVowelCount;
}

int main() {
  std::string s = "successes";
  std::cout << maxFreqSum(s) << std::endl;
  return 0;
}
