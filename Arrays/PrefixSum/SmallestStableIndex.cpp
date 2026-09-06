#include<bits/stdc++.h>
using namespace std;

int firstStableIndex(vector<int>&nums,int k){
	int n=nums.size();
	int stable_index = -1;
	for(int i=0;i<n;i++){
		int maximum = nums[i], minimum = nums[i];
		for(int j=0;j<=i;j++){
			maximum = max(maximum,nums[j]);
		}
		for(int k=i+1;k<n-1;k++){
			minimum = min(minimum,nums[k]);
		}
		if(maximum-minimum<=k){
			stable_index = i;
		}
	}
	return stable_index;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<firstStableIndex(arr,k)<<endl;
}