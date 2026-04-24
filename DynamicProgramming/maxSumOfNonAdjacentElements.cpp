#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>memo;

int calculateSum(vector<int>&nums,int i,int n){
	if(i==n){
		return nums[n];
	}
	if(i>n){
		return 0;
	}
	
	if(memo.find(i)!=memo.end()){
		return memo[i];
	}
	
	int pick = nums[i] + calculateSum(nums,i+2,n);
	int notPick = calculateSum(nums,i+1,n);
	
	return memo[i] = max(pick,notPick);
}

int nonAdjacent(vector<int>& nums) {
	int n = nums.size()-1;
	return calculateSum(nums,0,n);
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
	cout<<nonAdjacent(arr)<<endl;
}