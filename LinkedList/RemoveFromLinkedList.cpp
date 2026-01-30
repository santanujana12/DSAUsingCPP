#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *removeElements(Node *head, int val) {
  if (head == nullptr) {
    return nullptr;
  }
  Node *dummy = new Node(0);
  dummy->next = head;
  Node *curr = dummy;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->next->data == val) {
      Node *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    } else {
      curr = curr->next;
    }
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
  addNode(head, 7);
  addNode(head, 7);
  addNode(head, 6);
  addNode(head, 7);

  Node *removedElementNode = removeElements(head, 7);
  printLinkedList(removedElementNode); // Expected: 6
  return 0;
}
