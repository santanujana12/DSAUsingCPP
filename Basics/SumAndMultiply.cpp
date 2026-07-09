#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
	int rev=0;
	while(n>0){
		int d = n%10;
		if(d!=0){
			rev=rev*10+d;
		}
		n/=10;
	}
	return rev;
}

int findSum(int n){
	int sum=0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

long long sumAndMultiply(int n){
	long long removeZero=reverse(n);
	long long rev = reverse(removeZero);
	long long revSum = findSum(rev);
	return rev*revSum;
}

int main(){
	int n;
	cin>>n;
	cout<<sumAndMultiply(n);
}