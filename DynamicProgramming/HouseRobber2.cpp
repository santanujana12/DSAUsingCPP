#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>memo;

int maximizeRob(int i,int n,vector<int>&money){
	if(i>n){
		return 0;
	}
	if(i==n){
		return money[i];
	}
	if(memo.find(i)!=memo.end()){
		return memo[i];
	}
	int pick = money[i] + maximizeRob(i+2,n,money);
	int notPick = maximizeRob(i+1,n,money);
	
	return memo[i]=max(pick,notPick);
}

int houseRobber2(vector<int>& money) {
	if(money.size()==1){
		return money[0];
	}
	int n = money.size()-1;
	memo.clear();
    int case1 = maximizeRob(0,n-1,money);
    memo.clear();
    int case2 = maximizeRob(1, n, money);
    return max(case1, case2);
}

int main(){
	int n;
	cin>>n;
	vector<int>money;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		money.push_back(a);
	}
	cout<<houseRobber2(money)<<endl;
}