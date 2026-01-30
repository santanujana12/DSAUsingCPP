#include <iostream>
#include <stack>

class MyQueue {
private:
  std::stack<int> s1;
  std::stack<int> s2;

public:
  MyQueue() {}

  // Push element x to the back of queue
  void push(int x) { s1.push(x); }

  // Removes the element from the front of queue and returns it
  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int top = s2.top();
    s2.pop();
    return top;
  }

  // Get the front element
  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  // Returns true if the queue is empty
  bool empty() { return s1.empty() && s2.empty(); }
};

int main() {
  // Demonstration
  MyQueue q;
  q.push(1);
  q.push(2);
  std::cout << q.peek() << std::endl;                    // 1
  std::cout << q.pop() << std::endl;                     // 1
  std::cout << std::boolalpha << q.empty() << std::endl; // false
  return 0;
}
