#include<bits/stdc++.h>
using namespace std;

 string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> knowledgeMap;
    for (int i = 0; i < knowledge.size(); i++) {
        knowledgeMap[knowledge[i][0]] = knowledge[i][1];
    }
    string result = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            while (s[i] != ')') {
                temp += s[i];
                i++;
            }
            string temp_subStr = temp.substr(1);
            if (knowledgeMap.find(temp_subStr) != knowledgeMap.end()) {
                result += knowledgeMap[temp_subStr];
            } else {
                result += '?';
            }
            temp = "";
        } else {
            result += s[i];
        }
    }
    return result;
}

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<vector<string>>knowledge;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			string a;
			cin>>a;
			knowledge.push_back(a);
		}
	}
	string result = evaluate(s,knowledge);
	cout<<result<<endl;
}