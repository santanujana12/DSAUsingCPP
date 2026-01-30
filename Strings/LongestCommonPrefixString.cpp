#include <iostream>
#include <string>
#include <vector>


std::string longestCommonPrefix(std::vector<std::string> &strs) {
  if (strs.empty()) {
    return "";
  }

  std::string result = strs[0];
  for (int i = 1; i < strs.size(); i++) {
    int j = 0;
    while (j < result.length() && j < strs[i].length() &&
           result[j] == strs[i][j]) {
      j++;
    }
    result = result.substr(0, j);
    if (result.empty()) {
      return "";
    }
  }
  return result;
}

int main() {
  std::vector<std::string> s = {"flower", "flow", "flight"};
  std::cout << longestCommonPrefix(s) << std::endl;
  return 0;
}
