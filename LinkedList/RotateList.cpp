#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *rotateRight(Node *head, int k) {
  if (head == nullptr || head->next == nullptr || k == 0) {
    return head;
  }
  int length = 0;
  Node *curr = head;
  while (curr != nullptr) {
    length++;
    curr = curr->next;
  }

  k = k % length;
  if (k == 0) {
    return head;
  }
  curr = head;
  for (int i = 0; i < length - k - 1; i++) {
    curr = curr->next;
  }
  Node *tail = curr->next;
  curr->next = nullptr;
  Node *addAtHead = tail;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  tail->next = head;
  return addAtHead;
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
  addNode(head, 1);
  addNode(head, 2);
  addNode(head, 3);
  addNode(head, 4);
  addNode(head, 5);
  addNode(head, 6);

  Node *result = rotateRight(head, 10);
  printLinkedList(result);

  return 0;
}
