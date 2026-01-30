#include <algorithm>
#include <iostream>
#include <stack>


class MinStack {
private:
  std::stack<int> s;
  std::stack<int> m;

public:
  MinStack() {}

  void push(int val) {
    if (m.empty()) {
      m.push(val);
    } else {
      m.push(std::min(m.top(), val));
    }
    s.push(val);
  }

  void pop() {
    if (!s.empty() && !m.empty()) {
      s.pop();
      m.pop();
    }
  }

  int top() { return s.top(); }

  int getMin() { return m.top(); }
};

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  std::cout << minStack.getMin() << std::endl; // return -3
  minStack.pop();
  std::cout << minStack.top() << std::endl;    // return 0
  std::cout << minStack.getMin() << std::endl; // return -2
  return 0;
}
