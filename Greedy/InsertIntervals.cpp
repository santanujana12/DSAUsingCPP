#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>results;
       
    int i=0,n = intervals.size();
    // left non-overlapping
    while(i<n && intervals[i][1]<newInterval[0]){
    	results.push_back(intervals[i]);
        i++;
    }

    // overlapping
    while(i<n && intervals[i][0]<=newInterval[1]){
    	newInterval[0] = min(intervals[i][0],newInterval[0]);
        newInterval[1] = max(intervals[i][1],newInterval[1]);
        i++;
    }
    results.push_back(newInterval);

    // right non-overlapping
    while(i<n){
        results.push_back(intervals[i]);
        i++;
    }

    return results;
}

int main() {
	vector<vector<int>> intervals = {{1, 2}, {3, 10}, {12, 16}};
    vector<int> newInterval = {4, 5};

    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    vector<vector<int>> updatedIntervals = insert(intervals, newInterval);

    for (const auto& interval : updatedIntervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}