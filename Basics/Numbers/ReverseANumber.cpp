#include <iostream>
#include <cmath>
#include <climits>

int main() {
    int n = -1223;
    int originalNumber = n;
    int reverseNumber = 0;
    // std::abs for int is in <cstdlib> or <cmath> (overloaded)
    // Warning: std::abs(INT_MIN) is undefined behavior in C++, similar to Java
    n = std::abs(n);
    
    // Preserving original logic, though n is int and cannot exceed INT_MAX
    if (n > INT_MAX) {
        while (n > 0) {
            int rem = n % 10;
            reverseNumber = reverseNumber * 10 + rem;
            n /= 10;
        }
        if (originalNumber < 0) {
            std::cout << -reverseNumber << std::endl;
        } else {
            std::cout << reverseNumber << std::endl;
        }
    }
    return 0;
}
