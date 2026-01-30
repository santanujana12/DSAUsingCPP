#include <cstdlib> // for atoi or stoi
#include <iostream>
#include <stack>
#include <string>
#include <vector>


// Method to perform the operation based on the operator
int calculate(int a, int b, std::string sign) {
  char op = sign[0];
  switch (op) {
  case '+':
    return b + a;
  case '-':
    return b - a;
  case '/':
    return b / a;
  case '*':
    return b * a;
  default:
    return 0;
  }
}

// Method to evaluate the RPN expression
int evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> st;
  for (int i = 0; i < tokens.size(); i++) {
    std::string token = tokens[i];
    if (token != "+" && token != "-" && token != "*" && token != "/") {
      st.push(std::stoi(token)); // Push number onto the stack
    } else {
      int a = st.top();
      st.pop(); // Pop top element from the stack
      int b = st.top();
      st.pop(); // Pop next top element from the stack
      st.push(
          calculate(a, b, token)); // Perform the operation and push result back
    }
  }
  return st.top(); // The result is the top element of the stack
}

int main() {
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  int result = evalRPN(tokens);
  std::cout << "Result: " + std::to_string(result) << std::endl; // Output: 9
  return 0;
}
