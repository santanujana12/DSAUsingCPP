// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

unordered_map<int,int>memo;

int calculateJump(int i,int n,vector<int>&heights){
	if(i==n-1){
		return 0;
	}
	
	if(memo.find(i)!=memo.end()){
		return memo[i];
	}
	
	int oneStepCost = abs(heights[i]-heights[i+1])+calculateJump(i+1,n,heights);
	int twoStepCost = INT_MAX;
	
	if(i+2<n){
		twoStepCost = abs(heights[i]-heights[i+2])+calculateJump(i+2,n,heights);
	}
		
	return memo[i]=min(oneStepCost,twoStepCost); 
}

int frogJump(vector<int>&heights){
	int i=0,n=heights.size();
	return calculateJump(i,n,heights);
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
	
	cout<<frogJump(arr)<<endl;
}