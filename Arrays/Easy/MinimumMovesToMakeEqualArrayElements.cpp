#include<bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int moves=0, n = nums.size();

    for(int i=n-1;i>0;i--){
    	int diff = nums[i]-nums[0];
    	moves+=diff;
    }    
    return moves;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<minMoves(nums)<<endl;
}