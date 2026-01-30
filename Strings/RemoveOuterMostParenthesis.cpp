#include <iostream>
#include <string>

std::string removeOuterParentheses(std::string s) {
  std::string result = "";
  int openCount = 0;

  for (char ch : s) {
    if (ch == '(') {
      if (openCount > 0) {
        result += ch;
      }
      openCount++;
    } else if (ch == ')') {
      openCount--;
      if (openCount > 0) {
        result += ch;
      }
    }
  }

  return result;
}

int main() {
  std::string s = "(()())(())(()(()))";
  std::string result = removeOuterParentheses(s);
  std::cout << result << std::endl; // Output: ()()()()(())
  return 0;
}
