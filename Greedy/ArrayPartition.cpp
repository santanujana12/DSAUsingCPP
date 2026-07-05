#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int maxSum = 0;
    for(int i=0;i<nums.size();i+=2){
        maxSum+=nums[i];
    }

    return maxSum;
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
	
	cout<<arrayPairSum(nums)<<endl;
}