// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int lengthOfLIS(vector<int>& nums) {
   // considering each element to be a subsequence
   vector<int>dp(nums.size(),1);
   
   int largestLength = 1;

   for(int i=1;i<nums.size();i++){
   	// smaller elements on left
   	for(int j=0;j<i;j++){
   		if(nums[j]<nums[i]){
   			// current is max of current and previous
   			dp[i]=max(dp[i],dp[j]+1);
   			largestLength = max(largestLength,dp[i]);
   		}
   	}
   }
   return largestLength;
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
	
	cout<<lengthOfLIS(nums)<<endl;
}