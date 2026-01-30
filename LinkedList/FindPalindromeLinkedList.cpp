#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *reverseLinkedList(Node *head) {
  Node *curr = head;
  Node *prev = nullptr;
  while (curr != nullptr) {
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  head = prev;
  return head;
}

Node *findMiddleNode(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

bool findPalindrome(Node *head) {
  // If list is empty or single node, it is palindrome
  if (head == nullptr || head->next == nullptr)
    return true;

  Node *middle = findMiddleNode(head);
  Node *secondHalf = middle;
  Node *reversed = reverseLinkedList(secondHalf);
  Node *curr = head;
  Node *tempReversed = reversed;

  while (tempReversed != nullptr) {
    if (curr->data != tempReversed->data) {
      return false;
    }
    tempReversed = tempReversed->next;
    curr = curr->next;
  }
  return true;
}

bool isPalindrome(Node *head) { return findPalindrome(head); }

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

// Helper to print
void printLinkedList(Node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node *head = nullptr;
  addNode(head, 1);
  addNode(head, 2);
  addNode(head, 2);
  addNode(head, 1);

  printLinkedList(head);
  cout << boolalpha << isPalindrome(head) << endl;
  return 0;
}
