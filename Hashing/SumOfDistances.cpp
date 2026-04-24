// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

vector<long long> distance(vector<int>& nums) {
	int n = nums.size();
	vector<long long> arr(n, 0);
    unordered_map<int,vector<int>>groups;
    
    for(int i=0;i<n;i++){
    	groups[nums[i]].push_back(i);
    }
    
    for(auto i:groups){
    	vector<int>indices = i.second;
    	
    	long long leftSum=0;
    	long long leftCount=0;
    	
    	for(int i=0;i<indices.size();i++){
    		arr[indices[i]]+=(long long)indices[i]*leftCount-leftSum;
    		leftSum+=indices[i];
    		leftCount++;
    	}
    	
    	long long rightSum=0;
    	long long rightCount=0;
    	
    	for(int i=indices.size()-1;i>=0;i--){
    		arr[indices[i]] += rightSum - (long long)indices[i] * rightCount;
    		rightSum+=indices[i];
    		rightCount++;
    	}
    }
    return arr;
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
	vector<long long>arr = distance(nums);
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<endl;
}