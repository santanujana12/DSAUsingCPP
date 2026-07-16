#include<bits/stdc++.h>
using namespace std;

int gcdOfOddEvenSums(int n){
	int i=1,j=2,oddSum=0,evenSum=0;
	while(n>0){
		oddSum+=i;evenSum+=j;
		i+=2;j+=2;
		n--;
	}
	return gcd(oddSum,evenSum);
}

int main(){
	int n;
	cin>>n;
	cout<<gcdOfOddEvenSums(n)<<endl;
}