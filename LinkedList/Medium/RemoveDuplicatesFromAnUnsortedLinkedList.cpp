#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int,int>freq;
    ListNode *temp = head;
    while(temp!=NULL){
        freq[temp->val]++;
        temp = temp->next;
    }
    temp = head;
    ListNode *curr = new ListNode(-1);
    ListNode *finalHead = curr;

    while(temp!=NULL){
        if(freq[temp->val]<=1){
            curr->next = temp;
            curr = curr->next;
        }
        temp = temp->next;
    }
    curr->next = NULL;
    return finalHead->next;
}

int main(){
	
}