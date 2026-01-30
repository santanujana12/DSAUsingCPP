#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *addTwoNumbers(Node *head1, Node *head2) {
  Node *curr1 = head1;
  Node *curr2 = head2;
  Node *res = new Node(-1);
  Node *result = res;
  int carry = 0;
  while (curr1 != nullptr || curr2 != nullptr || carry != 0) {
    int sum = carry;
    if (curr1 != nullptr) {
      sum += curr1->data;
      curr1 = curr1->next;
    }
    if (curr2 != nullptr) {
      sum += curr2->data;
      curr2 = curr2->next;
    }
    carry = sum / 10;
    Node *addNode = new Node(sum % 10);
    result->next = addNode;
    result = result->next;
  }
  return res->next;
}

// Helper to print list
void printList(Node *node) {
  while (node != nullptr) {
    std::cout << node->data << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

// Helper to add node
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
  Node *head1 = nullptr;
  addNode(head1, 2);
  addNode(head1, 4);
  addNode(head1, 3); // 342

  Node *head2 = nullptr;
  addNode(head2, 5);
  addNode(head2, 6);
  addNode(head2, 4); // 465

  Node *result = addTwoNumbers(head1, head2); // 807
  printList(result);                          // Expected: 7 0 8

  return 0;
}
