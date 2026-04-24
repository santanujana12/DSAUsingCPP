#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>memo;

int calculateMinEnergy(vector<int>& heights,int n,int k,int minimum){
	if(n<=0){
		return 0;
	}
	
	if(memo.find(n)!=memo.end()){
		return memo[n];
	}
	
	for(int j=1;j<=k;j++){
		if(n-j>=0){
			int jump = calculateMinEnergy(heights,n-j,k,minimum)+abs(heights[n-j]-heights[n]);
			minimum = min(jump,minimum);
		}
		
	}
	
	return memo[n]=minimum;
}

int frogJump(vector<int>& heights, int k) {
	int n = heights.size()-1;
	int minimum = INT_MAX;
    return calculateMinEnergy(heights,n,k,minimum);
}


int main(){
	int n;
	cin>>n;
	vector<int>heights;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		heights.push_back(a);
	}
	int k;
	cin>>k;
	
	cout<<frogJump(heights,k)<<endl;
}