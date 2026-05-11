// Input and print written in the header file
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define ld long long double
using namespace std;

unordered_map<int,bool>mp;

bool checkPresence(string s, int i,int j, set<string>&word_dict){
	if(i==s.size()){
		return true;
	}
	if(i+j>s.size()){
		return false;
	}
	
	if(mp.find(i)!=mp.end()){
		return mp[i];
	}
	
	if(word_dict.find(s.substr(i,j))!=word_dict.end() && checkPresence(s,i+j,1,word_dict)){
		return mp[i]=true;
	}
	
	return mp[i]=checkPresence(s,i,j+1,word_dict);
}

bool wordBreak(string s, vector<string>& wordDict){
	
	set<string>word_dict(wordDict.begin(),wordDict.end());
	bool result = checkPresence(s,0,1,word_dict);
	
	return result;
}

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<string>wordDict;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		wordDict.push_back(a);
	}
	
	cout<<wordBreak(s,wordDict)<<endl;
}