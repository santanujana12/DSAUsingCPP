#include<bits/stdc++.h>
using namespace std;

 string removeOuterParentheses(string s) {
    stack<char>st;
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(!st.empty()){
                res+=s[i];
            }
            st.push(s[i]);
        }else{
            char c = st.top();
            st.pop();
            if(!st.empty()){
                res+=s[i];
            }
        }
    }
    return res;
}

int main(){
	string s;
	cin>>s;
	cout<<removeOuterParentheses(s)<<endl;
}