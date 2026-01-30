#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *removeNthFromEnd(Node *head, int n) {
  Node *dummy = new Node(0);
  dummy->next = head;
  Node *fast = dummy;
  Node *slow = dummy;
  int count = n;

  // Java Logic: while(count >= 0) fast = fast.next; count--;
  // This moves fast n+1 steps forward.
  // e.g., n=1. count=1, fast=dummy->next (head). count=0, fast=head->next.
  // count=-1 stop. gap between slow (dummy) and fast (head->next) is 2 steps.
  // Then move both until fast is null.
  // fast is at end. slow is n-1 steps from end? No n steps from end.
  // e.g. list 1->2->3. remove 1st from end (3). dummy->1->2->3.
  // n=1. fast starts at dummy.
  // loop runs for count=1,0.
  // count=1: fast=1.
  // count=0: fast=2.
  // count=-1: stop. fast at 2. slow at dummy.
  // while(fast!=null && fast.next!=null)...
  // fast=2. fast->next=3. Valid. fast=3, slow=1.
  // fast=3. fast->next=null. Valid loop cond? `fast!=null && fast.next!=null`.
  // fast->next is null. Stop. slow is 1. slow->next is 2. slow->next->next
  // is 3. delete slow->next (2). result 1->3. Wrong. We wanted to delete 3. BUT
  // checking the loop condition in Java carefully: `while(fast!=null &&
  // fast.next!=null)` And `count >= 0`. So it runs `n+1` times.

  // C++ reproduction:
  while (count >= 0) {
    if (fast == nullptr)
      break; // Safety
    fast = fast->next;
    count--;
  }

  while (fast != nullptr && fast->next != nullptr) {
    // std::cout << fast->data << ", " << slow->data << std::endl;
    fast = fast->next;
    slow = slow->next;
  }

  // slow is just before the one to delete
  if (slow->next != nullptr) {
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
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
  for (int i = 1; i <= 10; i++) {
    addNode(head, i);
  }
  int n = 5;
  Node *res = removeNthFromEnd(head, n);
  printLinkedList(res);
  return 0;
}
