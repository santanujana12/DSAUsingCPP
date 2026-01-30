#include <iostream>
#include <unordered_set>

int findSumOfSquares(int n) {
    int sum = 0;
    while(n > 0) {
        int d = n % 10;
        d *= d;
        sum += d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    std::unordered_set<int> freq;
    while(true) {
        n = findSumOfSquares(n);
        if(n == 1) {
            return true;
        } else if(freq.find(n) != freq.end()) {
            return false;
        } else {
            freq.insert(n);
        }
    }
}

int main() {
    int n = 2;
    std::cout << std::boolalpha << isHappy(n) << std::endl;
    return 0;
}
