#include<bits/stdc++.h>
using namespace std;

bool isSorted(string k){
	string temp = k;
	sort(temp.begin(),temp.end());
	return temp==k;
}

int minOperations(string s){
	if(isSorted(s)){
		return 0;
	}
	if(s.length()==2){
		return -1;
	}
	char mn='z',mx='a';
	for(int i=0;i<s.length();i++){
		mn = min(mn,s[i]);
		mx = max(mx,s[i]);
	}
	if(s[0]==mn || s[s.length()-1]==mx){
		return 1;
	}
	// if any mid has min or max sorting 2 parts needed
	for(int i=1;i<s.length()-1;i++){
		if(s[i]==mn || s[i]==mx){
			return 2;
		}
	}
	return 3;
}

int main(){
	string s;
	cin>>s;
	cout<<minOperations(s)<<endl;
}