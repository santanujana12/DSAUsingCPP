#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>&nums){
	sort(nums.begin(),nums.end());
	int n = nums.size();
	int a = nums[n-1]-1;
	int b = nums[n-2]-1;
	return a*b;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	
	cout<<maxProduct(nums)<<endl;
}