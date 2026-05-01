// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int maxProduct(vector<int>& nums) {
	
	if(nums.empty()) return 0;
	
    int max_product = nums[0];
    int max_current = nums[0];
    int min_current = nums[0];
    
    for(int i=1;i<nums.size();i++){
    	int prevMax = max_current;
    	max_current = max(nums[i],max(prevMax*nums[i],min_current*nums[i]));
    	min_current = min(nums[i],min(prevMax*nums[i],min_current*nums[i]));
    	max_product = max(max_current,max_product);
    }
   	
   	return max_product;
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
	
	cout<<maxProduct(nums)<<endl;
}