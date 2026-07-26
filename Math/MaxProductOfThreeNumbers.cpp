#include<bits/stdc++.h>
using namespace std;


int maximumProduct(vector<int>&nums){
	sort(nums.begin(),nums.end());
	int n = nums.size();
	// Last 3
	int nums1 = nums[n-1]*nums[n-2]*nums[n-3];
	// First 2 negative and last one
	int nums2 = nums[0]*nums[1]*nums[n-1];
	return max(nums1,nums2);
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
	cout<<maximumProduct(arr)<<endl;
}