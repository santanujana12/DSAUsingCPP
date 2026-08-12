#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    vector<vector<int>> result;
    for (int i = 0; i < image.size(); i++) {
        vector<int> a;
        for (int j = image[i].size() - 1; j >= 0; j--) {
            if (image[i][j] == 0) {
                a.push_back(1);
            } else {
                a.push_back(0);
            }
        }
        result.push_back(a);
    }
    return result;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>image;
	for(int i=0;i<n;i++){
		vector<int>a;
		for(int j=0;j<m;j++){
			int k;
			cin>>k;
			a.push_back(k);
		}
	}
	vector<vector<int>>result = flipAndInvertImage(image);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}