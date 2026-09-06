#include<bits/stdc++.h>
using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>left_max(n);
    vector<int>right_min(n);

    // find left max
    left_max[0] = nums[0];
    for(int i=1;i<n;i++){
        left_max[i] = max(left_max[i-1],nums[i]);
    }

    // find right min
    right_min[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        right_min[i]=min(right_min[i+1],nums[i]);
    }

    int instability_index=-1;
    for(int i=0;i<n;i++){
        if(left_max[i]-right_min[i]<=k){
            instability_index = i;
            break;
        }
	}
    return instability_index;
}


int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<firstStableIndex(arr,k)<<endl;
}