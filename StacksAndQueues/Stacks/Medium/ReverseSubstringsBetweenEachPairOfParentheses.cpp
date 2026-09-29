#include<bits/stdc++.h>
using namespace std;

string reverseParentheses(string s){
	stack<int>st;
    string result="";
    for(char ch:s){
        if(ch=='('){
            st.push(result.length());
        }else if(ch==')'){
            int start = st.top();
            st.pop();
            reverse(result.begin()+start,result.end());
        }else{
            result+=ch;
        }
    }
    return result;
}

int main(){
	string s;
	cin>>s;
	cout<<reverseParentheses(s)<<endl;
}