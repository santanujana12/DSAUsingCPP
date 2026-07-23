#include<bits/stdc++.h>
using namespace std;

// Another solution
 vector<int> intersectionAlt(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> sa(nums1.begin(),nums1.end());
    vector<int> res;
    for(int i=0;i<nums2.size();i++){
        if(sa.find(nums2[i]) != sa.end()){
            res.push_back(nums2[i]);
            sa.erase(nums2[i]);
        }
    }
    return res;
}

vector<int>intersection(vector<int>nums1,vector<int>&nums2){
	unordered_set<int>s1;
    unordered_set<int>s2;
    vector<int>result;
    for(int i=0;i<nums1.size();i++){
    	s1.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
    	s2.insert(nums2[i]);
    }
    
    for(auto i:s1){
    	if(s2.find(i)!=s2.end()){
    		result.push_back(i);
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
		int b;
		cin>>b;
		nums2.push_back(b);
	}
	
	vector<int>result = intersection(nums1,nums2);
	for(auto i:result){
		printf("%d ",i);
	}
}