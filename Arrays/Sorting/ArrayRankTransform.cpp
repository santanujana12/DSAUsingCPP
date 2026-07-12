/*https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12 */
#include<bits/stdc++.h>
using namespace std;

vector<int>arrayRankTransform(vector<int>&arr){
	vector<int>temp(arr.begin(),arr.end());
	sort(temp.begin(),temp.end());
	unordered_map<int,int>lookup;
	int j=1;
	for(int i=0;i<temp.size();i++){
		if(!lookup[temp[i]]){
			lookup[temp[i]]=j;
			j++;
		}
	}
	
	vector<int>res;
	for(int i=0;i<arr.size();i++){
		res.push_back(lookup[arr[i]]);
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
	vector<int>res = arrayRankTransform(arr);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}