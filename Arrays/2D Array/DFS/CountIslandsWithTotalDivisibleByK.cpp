#include<bits/stdc++.h>
using namespace std;

 int m, n;

long long dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
        return 0;
    }

    long long current_val = grid[r][c];
    grid[r][c] = 0; // Mark visited

    long long left = dfs(grid, r, c - 1);
    long long right = dfs(grid, r, c + 1);
    long long up = dfs(grid, r - 1, c);
    long long down = dfs(grid, r + 1, c);

    return current_val + left + right + up + down;
}

int countIslands(vector<vector<int>>& grid, int k) {
    m = grid.size();
    n = grid[0].size();

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                long long sumOfConnectedIslands = dfs(grid, i, j);
                if (sumOfConnectedIslands > 0 and
                    sumOfConnectedIslands % k == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	vector<vector<int>>grid;
	for(int i=0;i<m;i++){
		vector<int>arr;
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			arr.push_back(a);
		}
		grid.push_back(arr);
	}
	cout<<countIslands(grid,k)<<endl;
}