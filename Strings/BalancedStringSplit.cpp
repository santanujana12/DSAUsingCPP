#include <iostream>
#include <string>

int balancedStringSplit(std::string s) {
  int answer = 0;
  int balanceCount = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'R') {
      balanceCount++;
    } else if (s[i] == 'L') {
      balanceCount--;
    }
    if (balanceCount == 0) {
      answer++;
    }
  }
  return answer;
}

int main() {
  std::string s = "RLRRLLRLRL";
  std::cout << balancedStringSplit(s) << std::endl;
  return 0;
}
