#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>


int largestConsecutiveSequence(std::vector<int> &arr) {
  std::unordered_set<int> isPresent;

  for (int i = 0; i < arr.size(); i++) {
    isPresent.insert(arr[i]);
  }

  int maxCount = 0;

  for (int i : isPresent) {
    // if isPresent does'nt contain i+1 that means it's the starting element
    // JAVA CODE: if(!isPresent.contains(i-1))
    // This means if i-1 is NOT present, then 'i' is the start of a sequence.
    if (isPresent.find(i - 1) == isPresent.end()) {
      int count = 1;
      int elem = i; // Taking the current element

      while (isPresent.find(elem + 1) != isPresent.end()) {
        count++;
        elem++;
      }
      maxCount = std::max(count, maxCount);
    }
  }

  return maxCount;
}

int main() {
  std::vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::cout << largestConsecutiveSequence(arr) << std::endl;
  return 0;
}
