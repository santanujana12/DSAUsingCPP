#include <iostream>
#include <queue>

class ImplementStackUsingTwoQueues {

private:
  std::queue<int> q1;
  std::queue<int> q2;

public:
  ImplementStackUsingTwoQueues() {}

  void push(int x) { q1.push(x); }

  int pop() {
    while (q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    int result = q1.front();
    q1.pop();
    // Swap q1 and q2, but since std::swap is cheap on containers, we use it
    // Java Logic: queue<int> temp = q1; q1 = q2; q2 = temp;
    std::swap(q1, q2);
    return result;
  }

  int top() {
    while (q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    int result = q1.front();
    // Java Logic: q2.offer(q1.poll());
    q2.push(q1.front());
    q1.pop();

    std::swap(q1, q2);
    return result;
  }

  bool empty() { return q1.empty(); }
};

int main() {
  ImplementStackUsingTwoQueues stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << "Top element: " << stack.top() << std::endl; // Should print 30
  std::cout << "Popped element: " << stack.pop()
            << std::endl;                                     // Should print 30
  std::cout << "Top after pop: " << stack.top() << std::endl; // Should print 20
  std::cout << "Is stack empty? " << std::boolalpha << stack.empty()
            << std::endl; // Should print false

  stack.pop();
  stack.pop();
  std::cout << "Is stack empty now? " << std::boolalpha << stack.empty()
            << std::endl; // Should print true
  return 0;
}
