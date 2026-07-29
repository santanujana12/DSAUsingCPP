#include<bits/stdc++.h>
using namespace std;

int findLHS(vector<int>& nums) {
   sort(nums.begin(),nums.end());
   int n = nums.size(), maxLength=0;
   for(int i=0;i<n;i++){
   	int count=0,j=i;
   	while(j<n && nums[j]-nums[i]==0){
   		j++;
   	}
   	if(j<n and nums[j]-nums[i]==1){
   		count = j-i;
   		while(j<n and nums[j]-nums[i]==1){
   			j++;
   			count++;
   		}
   	}
   	
   	 maxLength=max(count,maxLength);
   }
   return maxLength;
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
	cout<<findLHS(nums)<<endl;
}