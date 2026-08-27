#include<bits/stdc++.h>
using namespace std;

string shortestBeautifulSubstring(string s,int k){
	string res="";
	int minLength = INT_MAX;
	for(int i=0;i<s.length();i++){
		string a = "";
		int kCount=0;
		for(int j=i;j<s.length();j++){
			a+=s[j];
			if(s[j]=='1'){
				kCount++;
			}
			if(kCount==k){
				break;
			}
		}
		
		int newSize = a.length();
		if(k==kCount){
			if(minLength>newSize){
				minLength = newSize;
				res = a;	
			}else if(minLength == newSize and a<res){
				// if previous size == newSize then compare if a>res
				res=a;
			}
		}
		
	}
	return res;
}

int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<shortestBeautifulSubstring(s,k)<<endl;
}