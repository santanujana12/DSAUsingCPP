#include<bits/stdc++.h>
using namespace std;


int calculateSubsequence(string s,string t,int i,int j,vector<vector<int>>&memo){
	if(j==0){
		return 1;
	}
	if(i==0){
		return 0;
	}

	if(memo[i][j]!=-1){
		return memo[i][j];
	}
	if(s[i-1]==t[j-1]){
		return memo[i][j] = calculateSubsequence(s,t,i-1,j-1,memo) + calculateSubsequence(s,t,i-1,j,memo);
	}
	return memo[i][j] = calculateSubsequence(s,t,i-1,j,memo);
	
}

int numDistinct(string s, string t) {
    int n=s.length();
    int m=t.length();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    return calculateSubsequence(s,t,n,m,memo);
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<numDistinct(s,t)<<endl;	
}