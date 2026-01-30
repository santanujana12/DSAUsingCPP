#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
  std::stack<char> bracket;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      bracket.push(ch);
    } else {
      if (bracket.empty()) {
        return false;
      } else if (ch == ')') {
        char top = bracket.top();
        if (top != '(') {
          return false;
        } else {
          bracket.pop();
        }
      } else if (ch == '}') {
        char top = bracket.top();
        if (top != '{') {
          return false;
        } else {
          bracket.pop();
        }
      } else if (ch == ']') {
        char top = bracket.top();
        if (top != '[') {
          return false;
        } else {
          bracket.pop();
        }
      }
    }
  }
  return bracket.empty();
}

int main() {
  // Hardcoded test since we don't scan in C++ demo
  std::string s = "()[]{}";
  bool result = isValid(s);
  if (result) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}
