#include<bits/stdc++.h>
using namespace std;

int numOfStrings(vector<string>& patterns, string word){
	int patternCount=0;
   	for(int i=0;i<patterns.size();i++){
   		string s = patterns[i];
   		if(word.find(s)!=-1){
   			patternCount++;
   		}
   	}
    
    return patternCount;
}

int main(){
	int n;
	cin>>n;
	vector<string>patterns;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		patterns.push_back(a);
	}
	string word;
	cin>>word;
	cout<<numOfStrings(patterns,word)<<endl;
}