#include<bits/stdc++.h>
using namespace std;

// void calculateDistinctSubsequence(string &s,int i,,string &curr,unordered_set<string>&s){
	// if(i==s.length()){
		// if(!curr.empty()){
			// st.insert(curr);
		// }
		// return;
	// }
// 	
	// // Pick
	// curr+=s[i];
	// calculateDistinctSubsequence(s,i+1,st,curr);
	// // Not pick and erase
	// curr.pop_back();
	// calculateDistinctSubsequence(s,i+1,st,curr);
// }

set<string> generate(string &s, int index, string curr) {
    if (index == s.size()) {
        return {curr};
    }

    auto take = generate(s, index + 1, curr + s[index]);
    auto notTake = generate(s, index + 1, curr);

    take.insert(notTake.begin(), notTake.end());

    return take;
}


int distinctSubseqII(string s){
	auto result = generate(s, 0, "");
    result.erase("");
    return result.size();
}

int distinctSubseqIIDP(string s) {
    const long long MOD = 1e9 + 7;
    long long dp = 1;
    long long last[26] = {};

    for (char c : s) {
        int x = c - 'a';
        long long newDp = (2 * dp - last[x] + MOD) % MOD;

        last[x] = dp;
        dp = newDp;
    }

    return (dp - 1 + MOD) % MOD;
}


int main(){
	string s;
	cin>>s;
	cout<<distinctSubseqII(s)<<endl;
}