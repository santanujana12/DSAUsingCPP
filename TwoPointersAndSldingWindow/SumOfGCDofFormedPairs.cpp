#include<bits/stdc++.h>
using namespace std;

long long gcdSum(vector<int>& nums){
		 int n = nums.size();
    vector<long long> prefixGcd(n, 0);
    int mx=INT_MIN;
   	for(int i=0;i<n;i++){
   		mx = max(nums[i],mx);
   		prefixGcd[i] = gcd(mx,nums[i]);
   	}
   	
   	sort(prefixGcd.begin(),prefixGcd.end());
   	long long gcdSum=0,i=0,j=n-1;
   	while(i<=j){
   		if(n%2!=0 and i==j){
   			break;
   		}
   		gcdSum += gcd(prefixGcd[i],prefixGcd[j]);
   		i++;j--;
   	}
   	return gcdSum;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		arr.push_back(a);
	}
	cout<<gcdSum(arr)<<endl;
}