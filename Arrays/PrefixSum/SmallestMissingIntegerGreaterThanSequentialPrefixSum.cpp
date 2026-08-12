#include<bits/stdc++.h>
using namespace std;

int missingInteger(vector<int>&nums){
	unordered_set<int>num_set(nums.begin(),nums.end());
	
	int sum = nums[0];
	for(int i=1;i<nums.size();i++){
		if(nums[i]==nums[i-1]+1){
			sum+=nums[i];
		}else{
			break;
		}
	}

	while(num_set.count(sum)){
		cout<<sum<<endl;
		sum+=1;
	}
	return sum;
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
	cout<<missingInteger(nums)<<endl;
}