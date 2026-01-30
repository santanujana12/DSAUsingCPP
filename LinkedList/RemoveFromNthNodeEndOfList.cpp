#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *removeNthFromEnd(Node *head, int n) {
  Node *dummy = new Node(0);
  dummy->next = head;
  int count = 0;
  Node *curr = dummy->next;
  while (curr != nullptr) {
    count++;
    curr = curr->next;
  }
  curr = dummy;
  for (int i = 0; i < count - n; i++) {
    curr = curr->next;
  }
  if (curr->next != nullptr) {
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
  }

  Node *res = dummy->next;
  // Don't delete dummy if returning dummy->next?
  // Wait, if dummy-next is the head, fine. We can delete dummy.
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
  for (int i = 1; i <= 1; i++) {
    addNode(head, i);
  }
  int n = 1;
  Node *res = removeNthFromEnd(head, n);
  printLinkedList(res);
  return 0;
}
