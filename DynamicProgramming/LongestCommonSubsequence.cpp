#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int findMaxLcs(string str1, int i, string str2, int j) {
    if (i >= str1.size() || j >= str2.size()) {
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if (str1[i] == str2[j]) {
        return dp[i][j]=1 + findMaxLcs(str1, i + 1, str2, j + 1);
    }
    
    return dp[i][j] = 0 + max(findMaxLcs(str1, i + 1, str2, j),findMaxLcs(str1, i, str2, j + 1));
}

int lcs(string str1, string str2) {
	memset(dp, -1, sizeof(dp));
	return findMaxLcs(str1,0,str2,0);
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	
	cout<<lcs(s1,s2)<<endl;
}