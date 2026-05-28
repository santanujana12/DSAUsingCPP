#include<bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k){
	if (nums.size() < 2) {
            return false;
    }

	set<int>s;
	int prevSum=0,sum=0;
	
	for(int i=0;i<nums.size();i++){
		prevSum = sum;
		sum=(sum+nums[i])%k;
		
		if(s.find(sum)!=s.end()){
			return true;
		}else{
			s.insert(prevSum);
		}
	}
	return false;
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
	int k;
	cin>>k;
	cout<<checkSubarraySum(nums,k)<<endl;
}