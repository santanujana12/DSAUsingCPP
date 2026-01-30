#include <iostream>
#include <vector>

std::vector<int> printSpiralMatrix(std::vector<std::vector<int>> &arr) {
  std::vector<int> result;
  if (arr.empty())
    return result;

  int left = 0, top = 0;
  int bottom = arr.size() - 1;
  int right = arr[0].size() - 1;

  while (left <= right && top <= bottom) {
    // Printing from left to right
    for (int i = left; i <= right; i++) {
      result.push_back(arr[top][i]);
    }
    top++;
    // Printing top to bottom
    for (int i = top; i <= bottom; i++) {
      result.push_back(arr[i][right]);
    }
    right--;

    // Printing from right to left
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        result.push_back(arr[bottom][i]);
      }
      bottom--;
    }

    // printing from bottom to top
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        result.push_back(arr[i][left]);
      }
      left++;
    }
  }
  return result;
}

int main() {
  std::vector<std::vector<int>> arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

  std::vector<int> result = printSpiralMatrix(arr);

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
