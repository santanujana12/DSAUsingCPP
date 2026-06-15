#include<bits/stdc++.h>
using namespace std;


int longestCommonSubstr(string str1, string str2){
 	int n = str1.length();
 	int m = str2.length();
 	
 	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
 	int maximum = 0;
 	
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			if(str1[i-1]==str2[j-1]){
 				dp[i][j] = dp[i-1][j-1]+1;
 				maximum = max(maximum,dp[i][j]);
 			}
 		}
 	}
 	return maximum;
}

int main(){
	string str1,str2;
	cin>>str1>>str2;
	cout<<longestCommonSubstr(str1,str2)<<endl;
}