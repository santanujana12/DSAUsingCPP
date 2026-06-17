#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int j=0,findMax=0;
    for(int i=0;i<s.size();i++){
        if(j<g.size() && g[j]<=s[i]){
            findMax++;
            j++;
        }
    }
    return findMax;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>child;
	vector<int>cookies;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		child.push_back(a);
	}	
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		cookies.push_back(a);
	}
	
	cout<<findContentChildren(child,cookies)<<endl;
}