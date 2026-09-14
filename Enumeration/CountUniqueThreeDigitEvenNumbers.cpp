#include<bits/stdc++.h>
using namespace std;

int totalNumbers(vector<int>& digits) {
	unordered_set<int>permutations;
	int n = digits.size();
	
	for(int i=0;i<n;i++){
		if(digits[i]==0){
			continue;
		}
		for(int j=0;j<n;j++){
			if(j!=i){
			 	for(int k=0;k<n;k++){
					if(j!=k && k!=i){
						int sum = digits[i]*100+digits[j]*10+digits[k];
						if(sum%2==0){
							permutations.insert(sum);
						}
					}
				}
			}
		}
	}
	return permutations.size();
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<totalNumbers(arr)<<endl;
}