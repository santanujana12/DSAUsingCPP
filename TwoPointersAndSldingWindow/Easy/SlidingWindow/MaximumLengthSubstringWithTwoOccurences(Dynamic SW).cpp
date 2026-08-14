#include<bits/stdc++.h>
using namespace std;

int maximumLengthSubstring(string s){
	unordered_map<char,int>freq;
	int left=0;
	int maximumLength=0;
	for(int right=0;right<s.length();right++){
		freq[s[right]]++;
		while(freq[s[right]]>2){
			freq[s[left]]--;
			left++;
		}
		maximumLength = max(maximumLength,right-left+1);
	}
	return maximumLength;
}

int main(){
	string s;
	cin>>s;
	cout<<maximumLengthSubstring(s)<<endl;
}