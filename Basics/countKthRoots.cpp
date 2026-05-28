#include<bits/stdc++.h>
using namespace std;

int countKthRoots(int l, int r, int k) {
	int a = l>0? floor(pow(l - 1, 1.0 / k) + 1e-9):0;
    int b = floor(pow(r, 1.0 / k) + 1e-9);
     
     int result = b-a;
     if(l<=0 and r>=0){
        result++;
     }

    return result;
}

int main(){
	int l,r,k;
	cin>>l>>r>>k;
	cout<<countKthRoots(l,r,k)<<endl;
}