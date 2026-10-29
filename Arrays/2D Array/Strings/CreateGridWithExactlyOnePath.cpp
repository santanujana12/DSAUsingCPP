#include<bits/stdc++.h>
using namespace std;

vector<string> createGrid(int m, int n) {
    vector<string>grid;
    // grid[0]
    string first="";
    for(int i=0;i<n;i++){
        first+='.';
    }
    grid.push_back(first);
    for(int i=1;i<m;i++){
        string rest;
        for(int j=0;j<n-1;j++){
            rest+='#';
        }
        rest+='.';
        grid.push_back(rest);
    }
    return grid;
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<string>result=createGrid(m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<result[i][j]<<" ";
		}
	}
}