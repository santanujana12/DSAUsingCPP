#include<bits/stdc++.h>
using namespace std;

int minimumPushes(string word){
	vector<int>freq(26,0);
	for(int i=0;i<word.length();i++){
		freq[word[i]-'a']++;
	}
	
	// Sorting in reverse order if frequency is higher means more used and assigned to one key
	sort(freq.rbegin(),freq.rend());
	int minimumCost=0;
	for(int i=0;i<26;i++){
		minimumCost += floor(i/8)*freq[i];
	}
	return minimumCost;
}

int main(){
	string word;
	cin>>word;
	cout<<minimumPushes(word)<<endl;	
}