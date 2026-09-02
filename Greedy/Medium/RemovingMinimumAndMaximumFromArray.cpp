#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(vector<int>&nums){
	int minValue=INT_MAX,minIndex=-1,maxValue=INT_MIN,maxIndex=-1;
	int n = nums.size();
	for(int i=0;i<n;i++){
		if(nums[i]>maxValue){
			maxValue=nums[i];
			maxIndex=i;
		}
		if(nums[i]<minValue){
			minValue=nums[i];
			minIndex=i;
		}
	}
	
	int deleteFromLeft=-1;
	if(maxIndex>minIndex){
		deleteFromLeft = maxIndex+1;
	}else{
		deleteFromLeft = minIndex+1;
	}
	
	int deleteFromRight=-1;
	if(maxIndex>minIndex){
		deleteFromRight = n-minIndex;
	}else{
		deleteFromRight = n-maxIndex;
	}
	
	int deleteFromBothEnds = -1;
	if(maxIndex>minIndex){
		deleteFromBothEnds = (minIndex+1)+(n-maxIndex);
	}else{
		deleteFromBothEnds = (maxIndex+1)+(n-minIndex);
	}

	return min(deleteFromLeft,min(deleteFromRight,deleteFromBothEnds));
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<minimumDeletions(arr)<<endl;
}