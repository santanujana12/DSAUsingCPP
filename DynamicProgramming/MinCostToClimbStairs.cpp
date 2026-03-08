// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

unordered_map<int,int>isPresent;

int findMinCost(vector<int>&cost,int n){
	if(n==0){
		return cost[0];
	}
	if(n==1){
		return cost[1];
	}
	if(isPresent.find(n) != isPresent.end()){
        return isPresent[n];
    }
	int oneStep = cost[n]+findMinCost(cost,n-1);
	int twoStep = cost[n]+findMinCost(cost,n-2);
	isPresent[n] = min(oneStep,twoStep);
	return isPresent[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    return min(findMinCost(cost,n-1),findMinCost(cost,n-2));
}

int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	
	cout<<minCostClimbingStairs(arr)<<endl;
}