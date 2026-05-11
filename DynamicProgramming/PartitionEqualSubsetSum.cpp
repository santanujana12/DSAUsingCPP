#include<bits/stdc++.h>
using namespace std;

unordered_map<long long,bool>mp;

bool isPartitionPossible(vector<int>& nums, int idx, int sum) {
    if(sum == 0){
    	 return true;
    }
       
    if(idx >= nums.size() || sum < 0){
    	return false;
    }
    
    long long key = ((long long)idx << 32) | sum;
    cout<<key<<endl;

    if(mp.find(key) != mp.end())
        return mp[key];

    bool take = isPartitionPossible(nums, idx + 1, sum - nums[idx]);
    bool skip = isPartitionPossible(nums, idx + 1, sum);

    return mp[key] = take || skip;
}

bool canPartition(vector<int>& nums){
	int totalSum = 0,currentSum=0;
	for(int i=0;i<nums.size();i++){
		totalSum+=nums[i];
	}
	if(totalSum%2!=0){
		return false;
	}
	return isPartitionPossible(nums,0,totalSum/2);
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
	cout<<canPartition(arr)<<endl;
}