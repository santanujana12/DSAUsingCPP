#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    if(n <= 0) {
        return 1;
    }
    return x * myPow(x, n - 1);
}

int main() {
    double x = 3.0;
    int n = 4;
    cout << myPow(x, n) << endl;
    return 0;
}
