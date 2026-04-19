#include<bits/stdc++.h>
using namespace std;

int calculatePoints(vector<vector<int>>& matrix,int i,int prevIndex,vector<vector<int>>& memo){
	if(i==matrix.size()){
		return 0;
	}
	
	 if (memo[i][prevIndex + 1] != -1){
	 	  return memo[i][prevIndex + 1];
	 }
      
	int maxPoints=0;
	for(int j=0;j<3;j++){
		if(j!=prevIndex){
			int sum = matrix[i][j]+calculatePoints(matrix,i+1,j,memo);
			maxPoints=max(sum,maxPoints);
		}
	}
	return memo[i][prevIndex+1]=maxPoints;
}

int ninjaTraining(vector<vector<int>>& matrix) {
	int maxPoints=0;
	vector<vector<int>> memo(matrix.size(), vector<int>(4, -1));
	return calculatePoints(matrix,0,-1,memo);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    cout << ninjaTraining(matrix) << endl;
}