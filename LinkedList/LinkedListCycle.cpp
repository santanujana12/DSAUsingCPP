#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

void addNode(Node *&head, int val) {
  Node *newNode = new Node(val);
  if (!head) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
}

int main() {
  Node *head = nullptr;
  for (int i = 1; i <= 10; i++) {
    addNode(head, i);
  }

  // Creating a cycle for testing?
  // Java code:
  // while(fast!=slow){ ... if(fast==null || fast.next==null) break ... }
  // The Java main method creates a list 1..10 WITHOUT a cycle.
  // Then it runs the loop check.
  // It initializes `Node slow = list.getHead(); Node fast = slow.next;`
  // And checks `while(fast != slow)`.
  // Since there is no cycle, `fast` will reach null, and it prints "No loop
  // detected". I will replicate this behavior.

  if (head == nullptr || head->next == nullptr) {
    std::cout << "No loop detected" << std::endl;
    return 0;
  }

  Node *slow = head;
  Node *fast = slow->next;

  bool loopDetected = false;
  while (fast != slow) {
    if (fast == nullptr || fast->next == nullptr) {
      std::cout << "No loop detected" << std::endl;
      loopDetected = false;
      break;
    }
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) { // Need to explicitly manage the break condition if loop
                        // finishes
      // Wait, the while condition `fast!=slow` handles it if they meet.
      // If they meet, loop terminates.
      // But if `fast` reaches null, we break inside.
      // If loop terminates because `fast == slow`, then loop detected.
      loopDetected = true;
    }
  }

  // Logic correction:
  // If we break from inside, loopDetected = false.
  // If while terminates, it means fast == slow.
  // Java code prints "Loop detected" at end. Assuming if it didn't break
  // inside.

  if (fast == slow) {
    std::cout << "Loop detected" << std::endl;
  }

  return 0;
}
