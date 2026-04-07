// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int memo[101][10001];

int calculate(vector<int>&coins,int i,int amount){
	if (amount == 0) {
        return 0;
    }
    if (i >= coins.size() or amount < 0) {
        return 1e9;
    }
	
	if (memo[i][amount] != -1) {
        return memo[i][amount];
    }
	int pick = 1 + calculate(coins,i,amount-coins[i]);
	int notPick = calculate(coins,i+1,amount);
	
	return memo[i][amount] = min(pick, notPick);
}

int coinChange(vector<int>& coins, int amount) {
	  for(int i = 0; i < 101; i++) {
        for(int j = 0; j <= amount; j++) {
            memo[i][j] = -1;
        }
    }

    int result = calculate(coins, 0, amount);
    return (result >= 1e9) ? -1 : result;
}

int main(){
	int n;
	cin>>n;
	vector<int>coins;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		coins.push_back(a);
	}
	int amount;
	cin>>amount;
	
	cout<<coinChange(coins,amount)<<endl;
}