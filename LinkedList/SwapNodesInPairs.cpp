#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *swapPairs(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  Node *dummy = new Node(-1);
  dummy->next = head;
  Node *prev = dummy;
  while (prev->next != nullptr && prev->next->next != nullptr) {
    Node *first = prev->next;
    Node *second = first->next;

    first->next = second->next;
    second->next = first;
    prev->next = second;
    prev = first;
  }
  Node *res = dummy->next;
  delete dummy;
  return res;
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
  for (int i = 1; i <= 6; i++) {
    addNode(head, i);
  }

  Node *result = swapPairs(head);
  printLinkedList(result);
  return 0;
}
