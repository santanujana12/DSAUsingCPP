#include<bits/stdc++.h>
using namespace std;

 vector<int> orArray(vector<int>& A) {
    vector<int>arr;
    for(int i=0;i<A.size()-1;i++){
	 	int a = A[i] | A[i+1];
        arr.push_back(a);
    }
    return arr;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>res = onArray(arr);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}