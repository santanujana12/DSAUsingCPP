#include<bits/stdc++.h>
using namespace std;

string smallestPalindrome(string s){
	int n=s.length();
	string a = s.substr(0,n/2);
	sort(a.begin(),a.end());
	string b = a;
	reverse(b.begin(),b.end());
	
	if(n%2!=0){
		return a+s[n/2]+b;
	}
	return a+b;
}

int main(){
	string s;
	cin>>s;
	cout<<smallestPalindrome(s)<<endl;	
}