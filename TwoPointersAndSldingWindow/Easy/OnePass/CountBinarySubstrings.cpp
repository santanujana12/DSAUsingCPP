#include<bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s) {
    int result=0,prev=0,flag=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
	        flag++;
        }
        else{
        // reset flag if different
	        prev=flag;
	        flag=1;
    	}
          // if flag==prev means equal zero equal one
        if(prev>=flag){
        	result++;
        }
    }
    return result;
}

int main(){
	string s;
	cin>>s;
	cout<<countBinarySubstrings(s)<<endl;
}