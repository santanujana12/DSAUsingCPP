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

  Node *slow = head;
  Node *fast = head;
  printLinkedList(head);

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  std::cout << slow->data << std::endl; // Should print 6 for 1..10

  return 0;
}
