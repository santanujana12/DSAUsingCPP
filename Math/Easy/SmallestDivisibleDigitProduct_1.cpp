#include<bits/stdc++.h>
using namespace std;

 int smallestNumber(int n, int t) {
    int digit_prod = 1;
    int temp=n;
    while(n!=0){
        digit_prod*=(n%10);
        n/=10;
    }
    if(digit_prod%t==0){
        return temp;
    }
    return smallestNumber(temp+1,t);
}

int main(){
	int n,t;
	cin>>n>>t;
	cout<<smallestNumber(n,t)<<endl;
	
}