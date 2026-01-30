#include <iostream>

int main() {
    int n = 4, flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (flag == 1) {
                std::cout << flag << " ";
                flag = 0;
            } else {
                std::cout << flag << " ";
                flag = 1;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
