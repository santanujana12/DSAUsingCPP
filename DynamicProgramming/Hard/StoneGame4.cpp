#include<bits/stdc++.h>
using namespace std;

bool winnerSquareGame(int n){
	vector<int>dp(n+1,false);
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=i;j++){
			if(!dp[i-j*j]){
				dp[i]=true;
				break;
			}
		}
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	cout<<winnerSquareGame(n);
}