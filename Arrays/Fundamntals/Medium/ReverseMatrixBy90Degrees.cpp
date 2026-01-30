#include <algorithm>
#include <iostream>
#include <vector>


void reverseMatrixBy90Degrees(std::vector<std::vector<int>> &matrix) {

  // Transposing of matrix
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i + 1; j < matrix[0].size(); j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  int n = matrix[0].size();
  // Reverse each row of matrix
  for (int i = 0; i < matrix.size(); i++) {
    // Logic from Java: reverse row
    // for (int j = 0; j < n / 2; j++) swap(matrix[i][j], matrix[i][n-j-1])
    std::reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  std::vector<std::vector<int>> matrix = {{1, 1, 2}, {5, 3, 1}, {5, 3, 5}};

  reverseMatrixBy90Degrees(matrix);

  for (const auto &row : matrix) {
    for (int val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
