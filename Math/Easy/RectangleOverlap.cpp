#include<bits/stdc++.h>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int rec1_x1 = rec1[0];
    int rec1_y1 = rec1[1];
    int rec1_x2 = rec1[2];
    int rec1_y2 = rec1[3];
    int rec2_x1 = rec2[0];
    int rec2_y1 = rec2[1];
    int rec2_x2 = rec2[2];
    int rec2_y2 = rec2[3];

    if (rec2_x1 < rec1_x2 and rec2_y1 < rec1_y2 and rec2_x2>rec1_x1 and rec2_y2>rec1_y1) {
        return true;
    }
    return false;
}

int main() {
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << isRectangleOverlap(rec1, rec2) << endl; // Output: true

    vector<int> rec3 = {0, 0, 1, 1};
    vector<int> rec4 = {1, 0, 2, 1};
    cout << isRectangleOverlap(rec3, rec4) << endl; // Output: false

    return 0;
}