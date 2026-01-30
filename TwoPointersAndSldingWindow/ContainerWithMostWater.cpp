#include <algorithm>
#include <iostream>
#include <vector>


int maxArea(std::vector<int> &height) {
  int max_area = -1;
  int i = 0, j = height.size() - 1;

  while (i < j) {
    // height[i], height[j]
    int area = std::min(height[i], height[j]) * (j - i);
    max_area = std::max(area, max_area);

    if (height[i] > height[j]) {
      j--;
    } else {
      i++;
    }
  }

  return max_area;
}

int main() {
  // Hardcoded input as per standard practice here
  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << maxArea(height) << std::endl;
  return 0;
}
