#include<bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
    stack<char>st;
    int i;
    for(i=0;i<s.length();i++){
	    if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
	        st.push(s[i]);
	    }else if(st.empty()){
	    	return false;
	    }else{
	        char c = st.top();
	        if((s[i]==')' and c!='(') or (s[i]==']' and c!='[') or (s[i]=='}' and c!='{')){
	            return false;
	        }else{
	            st.pop();
	        }
    	}
    }
    return i==s.size() && st.empty();
}

int main(){
	string s;
	cin>>s;
	cout<<isValid(s)<<endl;
}