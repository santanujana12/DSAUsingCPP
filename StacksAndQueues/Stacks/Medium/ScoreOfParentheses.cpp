#include<bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s){
	int score=0;
	stack<int>st;
	for(int i=0;i<s.length();i++){
		// if a new bracket encountered push current score and reset
		if(s[i]=='('){
			st.push(score);
			score=0;
		}else{
			// the bracket is closed
			if(s[i-1]=='('){
				score = st.top();
				score+=1;
			}else{
				// nested
				score = st.top()+2*score;
			}
			st.pop();
		}
	}
	return score;
}

int main(){
	string s;
	cin>>s;
	cout<<scoreOfParentheses(s)<<endl;
}