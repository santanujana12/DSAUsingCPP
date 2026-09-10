#include<bits/stdc++.h>
using namespace std;

long long countCommas(long long n) {
    if(n<1000){
        return 0;
    }
    long long count=0,p=1000;
    while(p<=n){
        count+=(n-p+1);
        p*=1000;
    }
    return count;
}

int main(){
	long long n;
	cin>>n;
	cout<<countCommas(n)<<endl;
}