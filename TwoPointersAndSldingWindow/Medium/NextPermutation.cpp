#include<bits/stdc++.h>
using namespace std;

/*
Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
Find the largest index l greater than k such that a[k] < a[l].
Swap the value of a[k] with that of a[l].
Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/

void nextPermutation(vector<int>&nums){
	int k=-1;
	for(int i=nums.size()-1;i>0;i--){
		if(nums[i]>nums[i-1]){
			k = i-1;
			break;
		}
	}
	
	if(k==-1){
		reverse(nums.begin(),nums.end());
		return;
	}
	
	int l=-1;
	 // find first element STRICTLY GREATER than nums[k] from right
	for(int i=nums.size()-1;i>k;i--){
		if(nums[i]>nums[k]){
			l = i;
			// Break immediately since the rightmost greater element is what we need
			break;
		}
	}
	
	swap(nums[k],nums[l]);
	int i=k+1,j=nums.size()-1;
	while(i<=j){
		swap(nums[i],nums[j]);
		i++;j--;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	nextPermutation(arr);
	for(auto i:arr){
		cout<<i<<endl;
	}
}