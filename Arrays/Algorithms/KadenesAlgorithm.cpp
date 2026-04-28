// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int maxSubArraySum(vector<int>& nums){
	int sum = nums[0], maxSum = nums[0];
	for(int i=1;i<nums.size();i++){
		sum = max(nums[i],sum+nums[i]);
		maxSum = max(maxSum,sum);
	}
	
	return maxSum;
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
	
	cout<<maxSubArraySum(arr)<<endl;
}