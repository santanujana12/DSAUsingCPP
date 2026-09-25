#include<bits/stdc++.h>
using namespace std;

int reverseDegree(string s) {
    int sum = 0;
    for(int i=0;i<s.length();i++){
    	int current = 123-int(s[i]);
    	sum+=current*(i+1);
    }   
    return sum;
}

int main(){
	string s;
	cin>>s;
	cout<<reverseDegree(s)<<endl;
}