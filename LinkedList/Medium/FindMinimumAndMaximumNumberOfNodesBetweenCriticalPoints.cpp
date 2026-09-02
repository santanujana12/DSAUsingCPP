#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> result;
    result.push_back(-1);
    result.push_back(-1);
    ListNode* prev = head;
    ListNode* curr = head->next;
    int currNodePos = 0;
    int prevCritPos = 0;
    int firstCritPos = 0;
    int minDistance = INT_MAX;
    int i = 1;

    while (curr->next != NULL) {
        if ((curr->val < prev->val and curr->val < curr->next->val) || (curr->val > prev->val and curr->val > curr->next->val)) {
            if (prevCritPos == 0) {
                firstCritPos = i;
                prevCritPos = i;
            } else {
                minDistance = min(minDistance, abs(i - prevCritPos));
                prevCritPos = i;
            }
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(minDistance!=INT_MAX){
        int maxDistance = prevCritPos-firstCritPos;
        result[0] = minDistance;
        result[1] = maxDistance;
    }
    return result;
}
