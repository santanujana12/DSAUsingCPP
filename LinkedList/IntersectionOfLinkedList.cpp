#include <iostream>
#include <unordered_set>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

Node *getIntersection(Node *headA, Node *headB) {
  Node *currA = headA;
  Node *currB = headB;
  std::unordered_set<int> freq;

  // This logic finds intersection by VALUE, not by REFERENCE/Node Identity.
  // Typical "Intersection of Linked List" problems (like LeetCode 160) ask for
  // the node where they merge. The provided Java code checks for intersection
  // by DATA values using a HashSet. It says: "Store all data from List B. Then
  // iterate List A, return first node whose data is in Set." This finds the
  // first node in A that has a value present in B. Converting this logic
  // exactly as is.

  while (currB != nullptr) {
    freq.insert(currB->data);
    currB = currB->next;
  }
  while (currA != nullptr) {
    if (freq.find(currA->data) != freq.end()) {
      return currA;
    }
    currA = currA->next;
  }
  return nullptr;
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

int main() {
  Node *headA = nullptr;
  for (int i = 1; i <= 5; i++) {
    addNode(headA, i);
  } // 1 2 3 4 5

  Node *headB = nullptr;
  for (int i = 4; i <= 10; i++) {
    addNode(headB, i);
  } // 4 5 6 7 8 9 10   <- Overlap by value starts at 4

  Node *result = getIntersection(headA, headB);
  if (result != nullptr) {
    std::cout << result->data << std::endl; // Should print 4
  } else {
    std::cout << "No intersection found" << std::endl;
  }
  return 0;
}
