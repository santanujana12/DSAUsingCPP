#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::vector<std::vector<std::string>>
groupAnagrams(std::vector<std::string> &strs) {
  std::vector<std::vector<std::string>> result;
  std::unordered_map<std::string, std::vector<std::string>> freq;

  for (const std::string &str : strs) {
    std::string sortedStr = str;
    std::sort(sortedStr.begin(), sortedStr.end());

    freq[sortedStr].push_back(str);
  }

  // Iterate over the map and push values to result
  for (auto const &[key, val] : freq) {
    result.push_back(val);
  }

  return result;
}

int main() {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> result = groupAnagrams(strs);

  for (const auto &group : result) {
    for (const auto &word : group) {
      std::cout << word << std::endl;
    }
  }
  return 0;
}
