#include<bits/stdc++.h>
using namespace std;

int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int>lookup(nums.begin(),nums.end());
    int prod=1;
    while(true){
    	if(lookup.find(prod*k)==lookup.end()){
    		return prod*k;
    	}
    	prod++;
    }
    return 0;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	cout<<missingMultiple(arr,k)<<endl;
}