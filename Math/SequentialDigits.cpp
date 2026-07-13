/* https://leetcode.com/problems/sequential-digits/ */
#include<bits/stdc++.h>
using namespace std;

bool checkSequential(int digits){
	int prev = digits%10;
	digits/=10;
	while(digits!=0){
		int curr = digits%10;
		if(prev-curr!=1){
			return false;
		}
		prev = curr;
		digits/=10;
	}
	return true;
}

vector<int>sequentialDigits(int low,int high){
	vector<int>result;
	// Generate all numbers between 1__ to 9__
	for(int i=1;i<=9;i++){
		int num = i;
		for(int j=i+1;j<=9;j++){
			num = num*10+j;
			if(num>=low and num<=high){
				result.push_back(num);
			}
		}
	}
	sort(result.begin(),result.end());
	return result;
}

int main(){
	int low,high;
	cin>>low>>high;
	vector<int>res = sequentialDigits(low,high);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<"\n";
	}
}