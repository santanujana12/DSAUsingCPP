// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int calculateSubstrings(string s,int i,int n){
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string res = s.substr(i,j-i+1);
			string rev = res;
			reverse(rev.begin(),rev.end());
			if(rev==res){
				l++;
			}
		}
	}
	return l;
}

int countSubstrings(string s){
	int i=0,n=s.size();
	return calculateSubstrings(s,i,n);
}

int main(){
	string s;
	cin>>s;
	cout<<countSubstrings(s)<<endl;
}