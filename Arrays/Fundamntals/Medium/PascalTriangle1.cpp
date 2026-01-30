#include <iostream>

// Find the value according to row and col given
// formula nCr
int findTheValue(int r, int c) {
  long long result = 1; // Use long long to prevent overflow during calculation
  if (c > r - c) {
    c = r - c;
  }
  if (c == 1) {
    return r;
  }
  // r is 1-based in the input?
  // Java code: row=14.
  // Loop: for(int i=0; i<c; i++) result = result * (r-i) / (i+1)
  // Formula nCr = n! / (r! (n-r)!)
  // If input is row 14, col 2. (0-indexed or 1-indexed?)
  // Usually pascal triangle nCr uses n-1, r-1 if 1-based.
  // Assuming the Java logic is what is desired.

  // Note: Java int might overflow for intermediate `result * (r-i)` if result
  // is large. Switched to long long in C++.
  for (int i = 0; i < c; i++) {
    result = result * (r - i);
    result /= (i + 1);
  }

  return (int)result;
}

int main() {
  int row = 14, column = 2;
  std::cout << findTheValue(row, column) << std::endl;
  return 0;
}
