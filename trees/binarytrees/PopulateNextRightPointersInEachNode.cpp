#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

Node *connectNode(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        Node *temp = NULL;
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (temp)
            {
                temp->next = curr;
            }
            temp = curr;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Node *head = connectNode(root);
    Node *start = head;
    while (start)
    {
        Node *curr = start;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
        Node *nextStart = nullptr;
        curr = start;
        while (curr && !nextStart)
        {
            if (curr->left)
                nextStart = curr->left;
            else if (curr->right)
                nextStart = curr->right;
            curr = curr->next;
        }
        start = nextStart;
    }
}