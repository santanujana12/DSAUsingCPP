#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int left,int right, string &s){
	while(left<right){
		if(s[left]!=s[right]){
			return false;
		}else{
			left++;right--;
		}
	}
	return true;
}

bool validPalindrome2(string s){
	int left = 0, right = s.size()-1;
	while(left<right){
		if(s[left]!=s[right]){
			return checkPalindrome(left+1,right,s)||checkPalindrome(left,right-1,s);
		}
		left++;right--;
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	cout<<validPalindrome2(s)<<endl;
}