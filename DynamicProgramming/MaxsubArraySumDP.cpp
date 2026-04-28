// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int maxSubArray(vector<int>&nums){
	int maxSum=INT_MIN, n = nums.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=nums[j];
			maxSum=max(maxSum,sum);
		}
	}
	return maxSum;
}

unordered_map<int,int>memo;

int calculateMaxSum(vector<int>&nums,int i){
	if(i==0){
		return nums[0];
	}
	
	if(memo.find(i)!=memo.end()){
		return memo[i];
	}
	
	int prev = calculateMaxSum(nums,i-1);
	
	return memo[i] = max(nums[i],nums[i]+prev);
}

int maxSubArrayRecursive(vector<int>&nums){
  	memo.clear();
    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        maxSum = max(maxSum, calculateMaxSum(nums, i));
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
	
	cout<<maxSubArrayRecursive(arr)<<endl;
}