#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *mergeTwoLists(Node *head1, Node *head2) {
  Node *result = new Node(-1);
  Node *dummy = result;
  while (head1 != nullptr && head2 != nullptr) {
    if (head1->data <= head2->data) {
      Node *addNode = new Node(head1->data);
      dummy->next = addNode;
      head1 = head1->next;
    } else {
      Node *addNode = new Node(head2->data);
      dummy->next = addNode;
      head2 = head2->next;
    }
    dummy = dummy->next;
  }

  if (head1 != nullptr) {
    dummy->next = head1;
  }

  if (head2 != nullptr) {
    dummy->next = head2;
  }

  return result->next;
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

void printList(Node *head) {
  while (head) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  Node *head1 = nullptr;
  addNode(head1, 1);
  addNode(head1, 2);
  addNode(head1, 4);
  addNode(head1, 5);

  Node *head2 = nullptr;
  addNode(head2, 1);
  addNode(head2, 3);
  addNode(head2, 4);
  addNode(head2, 5);
  addNode(head2, 6);

  Node *merged = mergeTwoLists(head1, head2);
  printList(merged);

  return 0;
}
