#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s){
	int maxDepth=0;
	int count=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			count++;
			maxDepth = max(maxDepth,count);
		}else if(s[i]==')' and maxDepth>0){
			count--;
		}
	}
	return maxDepth;
}

int main(){
	string s;
	cin>>s;
	cout<<maxDepth(s)<<endl;
}