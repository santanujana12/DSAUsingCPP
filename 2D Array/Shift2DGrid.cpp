#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
	vector<int>arr;
	int eachGridSize = grid[0].size()-1;
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			arr.push_back(grid[i][j]);
		}
	}
	
	//rotate the array K times
	k = k%arr.size();
	while(k>0){
		int last = arr[arr.size()-1];
		for(int i=arr.size()-1;i>0;i--){
			arr[i]=arr[i-1];
		}
		arr[0]=last;
		k--;
	}
	
	
	vector<vector<int>>result;
	for(int i=0;i<arr.size();){
		vector<int>inner;
		for(int j=0;j<=eachGridSize;j++){
			inner.push_back(arr[i]);
			i++;
		}
		result.push_back(inner);
	}
	
	return result;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>>grid;
	for(int i=0;i<n;i++){
		vector<int>arr;
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			arr.push_back(a);
		}
		grid.push_back(arr);
	}
	vector<vector<int>>result = shiftGrid(grid,k);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	
}