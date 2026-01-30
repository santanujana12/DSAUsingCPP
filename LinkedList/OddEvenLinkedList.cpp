#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *oddEvenList(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *even = head->next;
  Node *odd = head;
  Node *evenHead = even;

  // Check bounds carefully.
  // odd points to 1st, even points to 2nd.
  // while(even != null && even.next != null)
  // Java code: while (even.next != null && odd.next != null) seems correct but
  // C++ requires careful ptr access Wait, the Java code has: `while (even.next
  // != null && odd.next != null)` If even is last, even.next is null -> break.
  // If even is second to last. even.next is last. odd points to something
  // before even. Actually the standard logic is `while(even != nullptr &&
  // even->next != nullptr)` logic: odd->next = even->next; odd = odd->next;
  // even->next = odd->next; even = even->next; The Java code provided: odd.next
  // = odd.next.next; even.next = even.next.next; odd = odd.next; even =
  // even.next; This is risky if odd.next is null. The loop condition in Java
  // was `even.next != null && odd.next != null`. Let's implement that exactly.

  while (even != nullptr && even->next != nullptr && odd->next != nullptr) {
    // Wait, if even->next is valid, then odd->next (which is even) is valid.
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}

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

void printLinkedList(Node *head) {
  while (head) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  Node *head = nullptr;
  for (int i = 1; i <= 10; i++) {
    addNode(head, i);
  }

  Node *res = oddEvenList(head);
  printLinkedList(res);
  return 0;
}
