#include<bits/stdc++.h>
using namespace std;

bool isAdjacentDiffAtMostTwo(string s) {
    for(int i=0;i<s.length()-1;i++){
        int diff = abs((s[i]-'0')-(s[i+1]-'0'));
        cout<<diff<<endl;
        if(diff>2){
            return false;
        }
    }

    return true;
}


int main(){
	string s;
	cin>>s;
	cout<<isAdjacentDiffAtMostTwo(s)<<endl;
}