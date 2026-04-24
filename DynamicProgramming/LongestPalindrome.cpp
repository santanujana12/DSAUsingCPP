// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;


map<pair<int,int>,string>memo;

string largestPalindrome(string &s,int i,int j){
	if(i==0){
		return "";
	}
	if(j>s.size()-i){
		return largestPalindrome(s,i-1,0);
	}
	
	pair<int,int>key = {i,j};
	if(memo.find(key)!=memo.end()){
		return memo[key];
	}
	
	string res = s.substr(j,i);
	string rev = res;
	reverse(rev.begin(),rev.end());
	if(res==rev){
		return memo[key]=rev;
	}
	return memo[key]=largestPalindrome(s,i,j+1);
}

string longestPalindromeRecursive(string s){
	int i = s.size();
	int j = 0;
	memo.clear();
	return largestPalindrome(s,i,j);
}

bool isPalindrome(string s,int l,int r){
	while(l<=r){
		if(s[l]!=s[r]){
			return false;
		}
		l++;r--;
	}
	return true;
}

string longestPalindromeTwoPointer(string s) {
	int n = s.size();
	for(int i=n;i>0;i--){
		for(int j=0;j<=n-i;j++){
			int l = j;
            int r = j + i - 1;
			if(isPalindrome(s,l,r)){
				return s.substr(j,i);
			}
		}
	}
	return "";
}


int main(){
	string s;
	cin>>s;
	cout<<longestPalindromeTwoPointer(s)<<endl;
}