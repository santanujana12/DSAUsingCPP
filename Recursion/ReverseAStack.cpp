#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> arr;

    void reverse(stack<int>& st){
        if(st.empty()){
            return;
        }

        arr.push_back(st.top());
        st.pop();

        reverse(st);
    }

    void reverseStack(stack<int> &st) {
        reverse(st);

        for(auto i : arr){
            st.push(i);
        }
    }
};

int main() {
    stack<int> st;

    // pushing elements into stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    Solution obj;
    obj.reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}