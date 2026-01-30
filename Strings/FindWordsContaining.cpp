#include <iostream>
#include <string>
#include <vector>


std::vector<int> findWordsContaining(std::vector<std::string> &words, char x) {
  std::vector<int> result;
  for (int i = 0; i < words.size(); i++) {
    for (int j = 0; j < words[i].length(); j++) {
      if (words[i][j] == x) {
        result.push_back(i);
        break;
      }
    }
  }
  return result;
}

int main() {
  std::vector<std::string> words = {"abc", "bcd", "aaaa", "cbc"};
  char x = 'c';
  std::vector<int> results = findWordsContaining(words, x);
  for (int result : results) {
    std::cout << result << std::endl;
  }
  return 0;
}
