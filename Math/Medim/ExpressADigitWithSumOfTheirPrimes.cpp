#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
	if (n < 2){
		return false;
	}

    for(int i=2;i*i<=n;i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isSumOfTwoPrimes(int n) {
   for(int i=2;i<=n/2;i++){
   	if(is_prime(i) && is_prime(n-i)){
   		return true;
   	}
   }
   return false;
}

int main(){
	int n;
	cin>>n;
	cout<<isSumOfTwoPrimes(n)<<endl;
}