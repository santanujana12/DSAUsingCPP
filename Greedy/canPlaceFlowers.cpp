/* https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=greedy */
#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n){
	int l = flowerbed.size();
	int canPlace = 0,i=0;
    while(i<l){
    	if(flowerbed[i]==0){
    		bool leftLimit = (i==0 || flowerbed[i-1]==0);
	    	bool rightLimit = (i==l-1 || flowerbed[i+1]==0);
	    	
	    	if(leftLimit && rightLimit){
	    		canPlace++;
	    		flowerbed[i]=1;
	    	}
    	}
    	i++;
    }
    if(canPlace>=n){
    	return true;
    }
    
    return false;
}

int main(){
	int n,a;
	cin>>n>>a;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		arr.push_back(k);
	}
	cout<<canPlaceFlowers(arr,a)<<endl;
}