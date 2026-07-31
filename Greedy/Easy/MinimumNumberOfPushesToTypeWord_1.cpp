#include<bits/stdc++.h>
using namespace std;

int minimumPushes(string word) {
    int n = word.length();
    int minCost=0;
    for(int i=0;i<n;i++){
        minCost += floor(i/8)+1;
    }
    return minCost;
}

int main(){
	string s;
	cin>>s;
	cout<<minimumPushes(s)<<endl;	
}