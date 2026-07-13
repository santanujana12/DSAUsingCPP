#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/reverse-vowels-of-a-string/solutions/3723102/easy-solution-with-simple-explanation-us-lt1g/?envType=problem-list-v2&envId=two-pointers */
string reverseVowels(string s){
	int i=0,j=s.length()-1;
	set<char> vowels;
	vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
	vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');

	while(i<j){
		if(vowels.find(s[i])==vowels.end()){
			i++;
		}else if(vowels.find(s[j])==vowels.end()){
			j--;
		}else{
			swap(s[i],s[j]);
			i++;j--;
		}
	}
	return s;
}

int main(){
	string s;
	cin>>s;
	string result = reverseVowels(s);
	cout<<result<<endl;
}