#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static bool compare(const vector<int>& a, const vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
}

int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size() / 2;
    sort(costs.begin(), costs.end(), compare);
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	ans += costs[i][0];  // City A
    }
    for (int i = n; i < 2 * n; i++) {
        ans += costs[i][1];  // City B
    }
    return ans;
}


int main() {
    vector<vector<int>> costs = {
        {10, 20},
        {30, 200},
        {400, 50},
        {30, 20}
    };
    int result = twoCitySchedCost(costs);
    cout << "Minimum cost = " << result << endl;
}