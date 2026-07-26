#include<bits/stdc++.h>
using namespace std;

int maxProduct(int n){
	string s = to_string(n);
	int k = s.length();
	
	sort(s.begin(), s.end(), [](char a, char b) {
		return a-'0'<b-'0';
	});
	
	return (s[k-1]-'0')*(s[k-2]-'0');
}

int main(){
	int n;
	cin>>n;
	cout<<maxProduct(n)<<endl;	
}