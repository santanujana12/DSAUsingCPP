#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int>isPresent;
    for(int i=0;i<nums.size();i++){
    	// Sliding window
    	if(i>k){
    		isPresent.erase(nums[i-k-1]);
    	}

    	if(isPresent.find(nums[i])!=isPresent.end()){
    		return true;
    	}else{
    		isPresent.insert(nums[i]);
    	}
    }
    return false;
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
	cout<<containsNearbyDuplicate(nums,k)<<endl;
}