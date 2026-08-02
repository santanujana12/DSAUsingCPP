#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestDiff = INT_MAX;
    int resultSum = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int currentSum = nums[i] + nums[j] + nums[k];
            if (currentSum == target) {
                return currentSum;
            }
            // trying to get closer as much as possible and update result
            if (abs(currentSum - target) < closestDiff) {
                closestDiff = abs(currentSum - target);
                resultSum = currentSum;
            }
            if (currentSum < target) {
                j++;
            } else {
                k--;
            }
        }
    }

    return resultSum;
}

int main(){
	int n,target;
	cin>>n>>target;
	vector<int>nums;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	cout<<threeSumClosest(nums,target)<<endl;
}