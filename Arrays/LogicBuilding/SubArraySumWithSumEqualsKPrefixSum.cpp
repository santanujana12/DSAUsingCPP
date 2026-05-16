// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int res=0;
    int prefixSum=0;
    unordered_map<int,int>mp;
    mp[0]=1;

    for(int i=0;i<nums.size();i++){
        prefixSum+=nums[i];
        if(mp[prefixSum-k]>0){
            res+=mp[prefixSum-k];
        }else{
            res+=0;
        }
        mp[prefixSum]++;
    }
    return res;
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
	int k;
	cin>>k;
	cout<<subarraySum(arr,k)<<endl;
}