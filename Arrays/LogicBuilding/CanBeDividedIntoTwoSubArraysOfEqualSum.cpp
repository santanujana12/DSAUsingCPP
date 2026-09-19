#include<bits/stdc++.h>
using namespace std;

bool canBeDividedIntoTwoSubArraysOfEqualSum(vector<int>&arr,int n){
	int sumA=0,sumB=0;
	for(int i=0;i<n;i++){
		sumA+=arr[i];
	}
	for(int i=n-1;i>=0;i--){
		sumB+=arr[i];
		sumA-=arr[i];
		if(sumA==sumB){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<canBeDividedIntoTwoSubArraysOfEqualSum(arr,n)<<endl;
}