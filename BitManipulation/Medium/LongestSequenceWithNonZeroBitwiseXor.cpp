#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr) {
    int longestSub = 0, currentSub=0,currentLength=0;
    bool hasBecomeNonZero=false;
    for(int i=0;i<arr.size();i++){
    	currentSub^=arr[i];
    	currentLength++;
    	longestSub = max(currentLength,longestSub);
    	if(currentSub!=0){
    		hasBecomeNonZero=true;
    	}
    }
    
    
    if(currentSub==0 && hasBecomeNonZero){
    	return currentLength-1;
    }else if(!hasBecomeNonZero){
    	return 0;
    }
    return currentLength;
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
	cout<<longestSubsequence(arr)<<endl;
}