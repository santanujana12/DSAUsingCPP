#include<bits/stdc++.h>
using namespace std;

int largestInteger(vector<int>&nums,int k){
	unordered_map<int,int>freq;
	for(int i=0;i<nums.size();i++){
		freq[nums[i]]++;
	}
	
	int result = -1, n = nums.size();
	for(int i=0;i<n;i++){
		// All elements qualify if k==n
		if(k==n){
			result = max(result,nums[i]);
		}else if(freq[nums[i]]==1){
			// any unique elements qualify if k==1
			if(k==1){
				result = max(result,nums[i]);	
			}
			// boundary elements
			else if(!i || i==n-1){
				result = max(res,nums[i]);
			}
		}
	}
	return result;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>nums;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	cout<<largestInteger(nums,k)<<endl;
}