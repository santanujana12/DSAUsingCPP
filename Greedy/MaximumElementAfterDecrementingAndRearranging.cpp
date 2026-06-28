#include<bits/stdc++.h>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    arr[0]=1;
    for(int i=1;i<arr.size();i++){
        if((arr[i-1]<arr[i]) && (arr[i]-arr[i-1]>1)){
            arr[i]=arr[i-1]+1;
        }
    }
    return arr[arr.size()-1];
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
	cout<<maximumElementAfterDecrementingAndRearranging(arr)<<endl;
}