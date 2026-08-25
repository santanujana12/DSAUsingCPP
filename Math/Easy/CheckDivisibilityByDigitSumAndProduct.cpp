#include<bits/stdc++.h>
using namespace std;

bool checkDivisibility(int n) {
    long long prod=1;
    int sum=0;
    int temp = n;
    while(temp!=0){
        int d = temp%10;
        sum+=d;
        prod*=d;
        temp/=10;
    }
    if(n%(prod+sum)==0){
        return true;
    }
    return false;
}

int main(){
	int n;
	cin>>n;
	cout<<checkDivisibility(n)<<endl;
}