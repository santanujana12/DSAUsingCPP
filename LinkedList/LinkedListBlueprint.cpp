#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int size) : data(size), next(nullptr) {}
};

class LinkedListBlueprint {
private:
  Node *head;
  int size;

public:
  LinkedListBlueprint() : head(nullptr), size(0) {}

  Node *getHead() { return head; }

  int getSize() { return size; }

  void addNode(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
    this->size++;
  }

  void addAtHead(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    this->size++;
  }

  void addAtTail(int data) {
    addNode(data); // Same as addNode
  }

  void printLinkedList(Node *headNode) {
    if (headNode == nullptr) {
      std::cout << "Empty Linked List" << std::endl;
    } else {
      Node *curr = headNode;
      while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
      }
    }
    std::cout << std::endl;
  }

  void deleteNode(int data) {
    if (head == nullptr)
      return;

    if (head->data == data) {
      Node *temp = head;
      head = head->next;
      delete temp;
      this->size--;
    } else {
      Node *curr = head;
      while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data == data) {
          Node *takeNext = curr->next->next;
          delete curr->next;
          curr->next = takeNext;
          this->size--;
          return;
        } else {
          curr = curr->next;
        }
      }
      if (curr == nullptr || curr->next == nullptr) {
        std::cout << "No data found" << std::endl;
      }
    }
  }

  int getAtIndex(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    int count = 0;
    Node *curr = head;
    while (curr != nullptr) {
      if (count == index) {
        return curr->data;
      }
      curr = curr->next;
      count++;
    }
    return -1;
  }

  void addAtIndex(int data, int index) {
    if (index < 0 || index > size) {
      std::cout << "Invalid index" << std::endl;
      return;
    }
    if (index == 0) {
      addAtHead(data);
      return;
    }
    int count = 0;
    Node *curr = head;
    while (curr != nullptr) {
      if (count == index - 1) {
        Node *newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
        this->size++;
        return;
      }
      count++;
      curr = curr->next;
    }
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      std::cout << "Invalid index" << std::endl;
      return;
    }
    if (index == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
      this->size--;
      return;
    }

    int count = 0;
    Node *curr = head;
    while (curr != nullptr) {
      if (count == index - 1 && curr->next != nullptr) {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        this->size--;
        return;
      }
      count++;
      curr = curr->next;
    }
  }

  Node *reverseLinkedList(Node *headNode) {
    Node *curr = headNode;
    Node *prev = nullptr;

    while (curr != nullptr) {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    return prev;
  }
};

int main() {
  // Basic Test
  LinkedListBlueprint list;
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.printLinkedList(list.getHead());
  list.deleteNode(2);
  list.printLinkedList(list.getHead());
  return 0;
}
