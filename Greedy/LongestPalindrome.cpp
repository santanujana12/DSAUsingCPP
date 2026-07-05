/* https://leetcode.com/problems/longest-palindrome/description/?envType=problem-list-v2&envId=greedy */
#include<bits/stdc++.h>
using namespace std;

 int longestPalindrome(string s) {
    int longest = 0;
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    int oddCount = 0, evenCount = 0;
    for (auto const& [character, count] : freq) {
        if (count % 2 != 0) {
        	evenCount+=count-1;
            oddCount++;
        } else {
            evenCount+=count;
        }
    }
	
    if (oddCount >= 1) {
        return evenCount + 1;
    }
    return evenCount;
}

int main(){
	string s;
	cin>>s;
	cout<<longestPalindrome(s)<<endl;
}