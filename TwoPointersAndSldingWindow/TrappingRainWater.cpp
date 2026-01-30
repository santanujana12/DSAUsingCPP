#include <algorithm>
#include <iostream>
#include <vector>


int trap(std::vector<int> &height) {
  int totalWaterCount = 0;
  int n = height.size();

  if (n <= 2) {
    return 0;
  }

  std::vector<int> maxL(n);
  std::vector<int> maxR(n);

  maxL[0] = height[0];
  for (int i = 1; i < n; i++) {
    maxL[i] = std::max(maxL[i - 1], height[i]);
  }

  maxR[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    maxR[i] = std::max(maxR[i + 1], height[i]);
  }

  for (int i = 0; i < n; i++) {
    totalWaterCount += std::min(maxL[i], maxR[i]) - height[i];
  }

  return totalWaterCount;
}

int main() {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << trap(height) << std::endl;
  return 0;
}
