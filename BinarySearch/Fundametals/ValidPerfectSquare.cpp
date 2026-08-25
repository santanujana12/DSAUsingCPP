#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num){
	int l = 0,r = num,temp=num;
	while(l<=r){
		int mid = (l+r)/2;
		if(mid*mid==temp){
			return true;
		}
		if(mid*mid>temp){
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	return false;
}

int main(){
	int num;
	cin>>num;
	cout<<isPerfectSquare(num)<<endl;	
}