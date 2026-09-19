#include<bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string str = s+s;
    return str.find(s,1)!=s.length();   
}

int main(){
	string s;
	cin>>s;
	cout<<repeatedSubstringPattern(s)<<endl;
}