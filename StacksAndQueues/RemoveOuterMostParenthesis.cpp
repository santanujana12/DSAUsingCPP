#include <iostream>
#include <stack>
#include <string>

std::string removeOuterParentheses(std::string s) {
  std::string res;
  // Use the std::stack class, specifying the generic type <char>
  std::stack<char> st;

  for (int i = 0; i < s.length(); i++) {
    char currentChar = s[i];

    if (currentChar == '(') {
      // If the stack is NOT empty, it means we are inside an inner pair, so
      // append the '('
      if (!st.empty()) {
        res += currentChar;
      }
      // Push the current '(' onto the stack
      st.push(currentChar);
    } else {
      // When we encounter a ')', pop the matching '(' from the stack
      st.pop();
      // If the stack is NOT empty AFTER the pop, it means we are inside an
      // inner pair, so append the ')'
      if (!st.empty()) {
        res += currentChar;
      }
    }
  }

  return res;
}

int main() {
  std::string s = "(()())(())(()(()))";
  std::string result = removeOuterParentheses(s);
  std::cout << result << std::endl; // Output: ()()()()(())
  return 0;
}
