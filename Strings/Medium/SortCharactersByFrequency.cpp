#include<bits/stdc++.h>
using namespace std;

vector<char> frequencySort(string& s){
    unordered_map<char,int>freq;
    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
    }

    vector<pair<char,int>>toSort;
    for(auto i:freq){
        toSort.push_back({i.first,i.second});
    }
	
	sort(toSort.begin(), toSort.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
	    if (a.second != b.second) {
	        return a.second > b.second; // Higher frequency first
	    }
	    return a.first < b.first;       // Alphabetical order for ties
	});
	vector<char>res;
	for(int i=0;i<toSort.size();i++){
		 res.push_back(toSort[i].first);
	}
	return res;
}

int main(){
	string s;
	cin>>s;
	vector<char>res = frequencySort(s);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}