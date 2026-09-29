#include<bits/stdc++.h>
using namespace std;

int smallestIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        int temp = nums[i];
        while(temp!=0){
            int d = temp%10;
            sum+=d;
            temp/=10;
        }
        if(sum==i){
            return i;
        }
    }
    return -1;
}


int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<smallestIndex(nums)<<endl;
}