#include<bits/stdc++.h>
using namespace std;

int countCommas(int n){
	int countComma = 0;
	while(n>=1000){
		countComma++;
		n--;
	}
	return countComma;
}

int main(){
	int n;
	cin>>n;
	cout<<countCommas(n)<<endl;
}