#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
   set<int>s;
   for(int i:nums){
    	s.insert(i);
    }
    int k = s.size();
    int j=0;
    for(int i:s){
        nums[j++]=i;
    }
    return j;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int res = removeDuplicates(arr);
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<"\n"<<res<<endl;
}