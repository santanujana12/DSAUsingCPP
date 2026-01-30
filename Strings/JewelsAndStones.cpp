#include <iostream>
#include <string>

int numJewelsInStones(std::string jewels, std::string stones) {
  int count = 0;
  for (int i = 0; i < stones.length(); i++) {
    for (int j = 0; j < jewels.length(); j++) {
      if (jewels[j] == stones[i]) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  std::string jewels = "aA";
  std::string stones = "aAAbbbb";
  std::cout << numJewelsInStones(jewels, stones) << std::endl;
  return 0;
}
