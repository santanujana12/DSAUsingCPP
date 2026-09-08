#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int data): val(data),next(NULL){}
};

Node* mergeKLists(vector<Node*>& lists) {
    vector<int> array;
    for(int i=0;i<lists.size();i++){
        Node *head = lists[i];
        while(head!=NULL){
            array.push_back(head->val);
            head = head->next;
        }
    }
    if(array.size()==0){
        return NULL;
    }
    sort(array.begin(),array.end());
    Node *head = new Node(array[0]);
    Node *temp = head;
    temp->next = NULL;
    for(int i=1;i<array.size();i++){
        Node *newNode = new Node(array[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// Helper function to create a linked list from a vector
Node* createList(const vector<int>& nums) {
    if (nums.empty()) return NULL;
    Node* head = new Node(nums[0]);
    Node* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new Node(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    // 1. Create individual sorted linked lists
    Node* list1 = createList({1, 4, 5});
    Node* list2 = createList({1, 3, 4});
    Node* list3 = createList({2, 6});

    // 2. Group them into a vector of Node pointers
    vector<Node*> lists = {list1, list2, list3};

    cout << "Original Lists:" << endl;
    cout << "List 1: "; printList(list1);
    cout << "List 2: "; printList(list2);
    cout << "List 3: "; printList(list3);
    cout << "-------------------------------" << endl;

    // 3. Call your mergeKLists function
    Node* mergedHead = mergeKLists(lists);

    // 4. Print the final merged and sorted list
    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
