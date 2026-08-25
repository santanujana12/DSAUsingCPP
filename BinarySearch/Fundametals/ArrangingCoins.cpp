#include<bits/stdc++.h>
using namespace std;

int arrangeCoins(int n){
	int low = 1;
	int high = n;
	int ans = 1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if((long)mid*(mid+1)/2<=n){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	cout<<arrangeCoins(n)<<endl;
}