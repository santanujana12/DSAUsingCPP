#include<bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c) {
    int n = s.length();
    vector<int> distance1(n);
    vector<int> distance2(n);
    
    // 1. Forward Pass: Find the closest 'c' to the left of index i
    int last_seen = -n; // Initialize with a far away index
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            last_seen = i;
        }
        distance1[i] = i - last_seen;
    }
    
    // 2. Backward Pass: Find the closest 'c' to the right of index i
    last_seen = 2 * n; // Initialize with a far away index
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) {
            last_seen = i;
        }
        distance2[i] = last_seen - i;
    }
    
    // 3. Combine: Take the absolute minimum distance from either direction
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = min(distance1[i], distance2[i]);
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    char c;
    cin >> c;
    vector<int> result = shortestToChar(s, c);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}
