#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s){
	int openCount=0,closeCount=0;
	stack<char>st;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			st.push(s[i]);
			openCount++;
		}else{
			if(!st.empty()){
				char c = st.top();
				if(c=='('){
					openCount--;
					st.pop();
				}else{
					closeCount++;
				}
			}else{
				closeCount++;
			}
		}
	}
	return openCount+closeCount;
}

int main(){
	string s;
	cin>>s;
	cout<<minAddToMakeValid(s)<<endl;
}