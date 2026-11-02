#include<bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int minMoves=0;
    int mid = n/2;
    int median = nums[n/2];
    for(int i=0;i<n;i++){
    	minMoves+=abs(nums[i]-median);
    }    
    return minMoves;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<minMoves2(arr)<<endl;
}