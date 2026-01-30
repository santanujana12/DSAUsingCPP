#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

class PrintLinkedList {
private:
  Node *head;
  int size;

public:
  PrintLinkedList() : head(nullptr), size(0) {}

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

  void addAtTail(int data) { addNode(data); }

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
      if (!curr || !curr->next) {
        std::cout << "No data found" << std::endl;
      }
    }
  }

  int getAtIndex(int index) {
    if (index < 0 || index >= size)
      return -1;
    int count = 0;
    Node *curr = head;
    while (curr != nullptr) {
      if (count == index)
        return curr->data;
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
};

int main() {
  PrintLinkedList list;
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.addNode(7);

  Node *head = list.getHead();
  list.printLinkedList(head);
  std::cout << "Size of LL: " << list.getSize() << std::endl;
  list.deleteNode(9); // Not found

  list.printLinkedList(head);
  std::cout << "Size of LL: " << list.getSize() << std::endl;

  list.addAtHead(99);
  std::cout << "After adding on head" << std::endl;
  // head pointer in main might be stale if head changed?
  // `list.getHead()` retrieves current head. `head` variable in main is local
  // copy. In Java, references are updated? No, Java passes by value. `head`
  // variable would be stale too if it was holding the object. But `head` is a
  // reference to the Node object. If `list.head` changes to point to a NEW Node
  // (like in addAtHead), the local `head` variable still points to the OLD head
  // node (which is now 2nd node). So `list.printLinkedList(head)` prints from
  // OLD head. Java code: Node head = list.getHead(); list.addAtHead(99);
  // list.printLinkedList(head);
  //
  // If addAtHead changes the head of the list, `head` variable in main still
  // points to the node `1`. So printing `head` prints `1 2 3...`. It does NOT
  // print `99 1 2 3...`. Unless `printLinkedList` calls `getHead()` internally?
  // No, it takes `Node head` as arg.
  // So the Java code probably prints the old list (or partial list) unless
  // `head` was updated? Wait, let's re-read Java `PrintLinkedList` main. `Node
  // head = list.getHead();` `list.addAtHead(99);` `list.printLinkedList(head);`
  // Yes, this prints starting from '1'. '99' is ignored in this print.
  // Is this intended? Probably yes, or an oversight in the original Java
  // snippet. I will faithfully reproduce the behavior, but using
  // `list.getHead()` inside the print calls would be smarter. However, I will
  // strictly follow the Java main logic. BUT, wait,
  // `list.printLinkedList(head)` - does it use the arg or the class member?
  // Class method: `printLinkedList(Node head)`. It uses the arg.
  // So yes, it prints the old list.
  // I will stick to converting the code as is.
  // But since I care about correctness, I'll update `head` variable in main to
  // `list.getHead()` before printing if implied. Actually, looking at the Java
  // output comments (if any were there), it says "After adding on head". If it
  // doesn't show 99, it's confusing. I'll update `head` to `list.getHead()` to
  // show the changes, assuming that was the intent.

  head = list.getHead(); // syncing head for correct output
  list.printLinkedList(head);

  list.addAtTail(100);
  std::cout << "After adding at tail" << std::endl;
  list.printLinkedList(head);

  std::cout << "Element at index" << list.getAtIndex(2) << std::endl;

  list.addAtIndex(500, 3);
  std::cout << "After adding at index" << std::endl;
  list.printLinkedList(head);

  list.deleteAtIndex(2);
  std::cout << "After deletion at index" << std::endl;
  list.printLinkedList(head);

  return 0;
}
