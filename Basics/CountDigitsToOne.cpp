#include<bits/stdc++.h>
using namespace std;

int digitalRoot(int n){
	if(n/10==0){
		return n;
	}
	
	int sum=0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	
	if(sum/10!=0){
		return digitalRoot(sum);
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	cout<<digitalRoot(n)<<endl;
}