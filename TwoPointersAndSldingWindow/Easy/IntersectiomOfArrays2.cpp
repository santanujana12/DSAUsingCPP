#include<bits/stdc++.h>
using namespace std;

vector<int>intersect(vector<int>&nums1,vector<int>&nums2){
	multiset<int>isPresent;
	for(int i=0;i<nums1.size();i++){
		isPresent.insert(nums1[i]);
	}
	vector<int>result;
	for(int i=0;i<nums2.size();i++){
		auto it = isPresent.find(nums2[i]);

		if (it != isPresent.end()) {
		    result.push_back(nums2[i]);
		    isPresent.erase(it);
		}
	}
	return result;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>nums1;
	vector<int>nums2;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums1.push_back(a);
	}	
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		nums2.push_back(a);
	}
	vector<int>result = intersect(nums1,nums2);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}