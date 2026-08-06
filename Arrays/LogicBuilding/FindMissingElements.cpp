#include<bits/stdc++.h>
using namespace std;

 vector<int> findMissingElements(vector<int>& nums) {
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int n = nums.size();
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        minimum = min(minimum,nums[i]);
        maximum = max(maximum,nums[i]);
        s.insert(nums[i]);
    }

    vector<int>result;
    for(int i=minimum;i<maximum;i++){
        if(s.find(i)==s.end()){
            result.push_back(i);
        }
    }
        
    return result;
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
	vector<int>result = findMissingElements(nums);
	for(auto i:nums){
		cout<<i<<" ";
	}
	cout<<endl;
}