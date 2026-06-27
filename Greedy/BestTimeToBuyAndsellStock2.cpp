#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
	int profit=0;
	for(int i=1;i<prices.size();i++){
		if(prices[i-1]<prices[i]){
			profit+=(prices[i]-prices[i-1]);
		}
		
	}
	return profit;
}

int main(){
	int n;
	cin>>n;
	vector<int>prices;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		prices.push_back(a);
	}
	cout<<maxProfit(prices)<<endl;
}