#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *deleteDuplicates(Node *head) {
  Node *curr = head;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->data == curr->next->data) {
      Node *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    } else {
      curr = curr->next;
    }
  }
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
    addNode(head, i);
  } // 1 1 2 2 ...

  Node *result = deleteDuplicates(head);
  printLinkedList(result); // 1 2 3 ...
  return 0;
}
