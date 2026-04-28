// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

unordered_map<int,int>mp;

int calculateGroups(int i,int n,string s){
	if(i==n){
		return 1;
	}
	if(s[i]=='0'){
		return 0;
	}
	
	if(mp.find(i)!=mp.end()){
		return mp[i];
	}
	
	int result = calculateGroups(i+1,n,s);
	if(i+1<n){
		int doubleTake = stoi(s.substr(i,2));
		if(doubleTake>=10 and doubleTake<=26){
			result+=calculateGroups(i+2,n,s);
		}
	}
	mp[i]=result;
	return result;
}

int numDecodings(string s) {
	int n = s.size();
	return calculateGroups(0,n,s);
}

int main(){
	string s;
	cin>>s;
	cout<<numDecodings(s)<<endl;
}