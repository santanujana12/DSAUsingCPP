#include <iostream>

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
  // For odd length, middle is the exact middle. For even, it's the start of
  // second half. Actually standard slow/fast finds: 1->2->2->1. Slow at 2nd
  // '2'. 1->2->3->2->1. Slow at '3'.

  // We should reverse from middle (inclusive or next?).
  // Java code: Node secondHalf = middle; Node reversed =
  // reverseLinkedList(secondHalf); This reverses the second half OF THE
  // ORIGINAL LIST. This modifies the list structure. If we reverse starting
  // from middle, the first half points to middle. And middle now points to
  // prev... Let's stick to the logic provided.

  Node *secondHalf = middle;
  Node *reversed = reverseLinkedList(secondHalf);
  Node *curr = head;
  Node *tempReversed = reversed; // Keep head of reversed to restore later if
                                 // needed (not done in java code)

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
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  Node *head = nullptr;
  addNode(head, 1);
  addNode(head, 2);
  addNode(head, 2);
  addNode(head, 1);

  printLinkedList(head);
  std::cout << std::boolalpha << isPalindrome(head) << std::endl;
  return 0;
}
