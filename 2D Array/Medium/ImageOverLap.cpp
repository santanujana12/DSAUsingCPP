#include<bits/stdc++.h>
using namespace std;

int largestOverlap(vector<vector<int>>&img1,vector<vector<nt>>&img2){
	int maxOverLap=0;
	int n = img1[0].size();
	for(int down = -(n-1);down<=(n-1);down++){
		for(int right=-(n-1);right<=(n-1);right++){
			int currentOverlap=0;
			for(int row=0;row<n;row++){
				for(int col=0;col<n;col++){
					if(img1[row][col]==1){
						int newRow = down+row;
						int newCol = right+col;
						if((newRow>=0 and newRow<n) and (newCol>=0 and newCol<n)){
							if(img2[newRow][newCol]==1){
								currentOverlap++;
							}
						}
					}
				}
			}
			maxOverLap = max(currentOverlap,maxOverLap);
		}
	}
	return maxOverLap;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>img1;
	vector<vector<int>>img2;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int j=0;j<m;j++){
			img1.push_back(a);
		}
	}
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int j=0;j<m;j++){
			img2.push_back(a);
		}
	}
	
	cout<<largestOverlap(img1,ing2)<<endl;
}