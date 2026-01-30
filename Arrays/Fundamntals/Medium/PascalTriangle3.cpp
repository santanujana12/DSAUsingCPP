#include <iostream>
#include <vector>

std::vector<std::vector<int>> pascalTriangle(int n) {
  std::vector<std::vector<int>> result;
  for (int i = 0; i < n; i++) {
    std::vector<int> eachRow;
    eachRow.push_back(1);
    // Add top rows and push to each rows
    for (int j = 1; j < i; j++) {
      eachRow.push_back(result[i - 1][j - 1] + result[i - 1][j]);
    }
    if (i > 0) {
      eachRow.push_back(1);
    }
    result.push_back(eachRow);
  }

  return result;
}

int main() {
  int n = 6;
  std::vector<std::vector<int>> result = pascalTriangle(n);

  for (const auto &row : result) {
    std::cout << "[";
    for (size_t i = 0; i < row.size(); i++) {
      std::cout << row[i] << (i < row.size() - 1 ? ", " : "");
    }
    std::cout << "] ";
  }
  std::cout << std::endl;
  return 0;
}
