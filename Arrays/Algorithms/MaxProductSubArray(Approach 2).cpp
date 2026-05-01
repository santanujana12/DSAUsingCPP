// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int maxProduct(vector<int>& nums) {
    int ltrProduct=1, rtlProduct=1;
    int maxProd = INT_MIN;

    for(int i=0;i<nums.size();i++){
        ltrProduct*=nums[i];
        maxProd = max(maxProd,ltrProduct);
        if(ltrProduct==0){
            ltrProduct=1;
        }
    }

    for(int i=nums.size()-1;i>=0;i--){
        rtlProduct*=nums[i];
        maxProd = max(maxProd,rtlProduct);
        if(rtlProduct==0){
            rtlProduct = 1;
        }
    }

    return maxProd;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	cout<<maxProduct(arr)<<endl;
}