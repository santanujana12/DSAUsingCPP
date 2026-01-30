#include <iostream>
#include <unordered_map>
#include <vector>


// Space complexity O(n)
int findMajorityElement(std::vector<int> &arr) {
  int result = -1;
  int n = arr.size();

  std::unordered_map<int, int> freq;

  // add frequency to check for each values
  for (int i = 0; i < arr.size(); i++) {
    freq[arr[i]]++; // Simplified map access
  }

  // Now checking if the value of each value freq is greater than n/2
  for (int i = 0; i < arr.size(); i++) {
    int value = freq[arr[i]];
    if (value >= n / 2) { // Logic from Java: >= n/2. Usually Majority is > n/2.
                          // But I'll stick to provided code logic
      result = arr[i];
      break;
    }
  }
  return result;
}

// further optimizing Moore's voting algorithm
int MooresVotingAlgorithm(std::vector<int> &arr) {
  int element = 0;
  int count = 0;
  // checking if the current element is equal to next element then increase the
  // count else decrease the count if count becomes equal to 0 then change the
  // element
  for (int i = 0; i < arr.size(); i++) {
    if (count == 0) {
      count = 1;
      element = arr[i];
    } else if (element != arr[i]) {
      count--;
    } else {
      count++;
    }
  }

  int finalCount = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == element) {
      finalCount++;
    }
  }

  if (finalCount >= (arr.size() / 2)) {
    return element;
  }
  return 0;
}

int main() {
  std::vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  std::cout << MooresVotingAlgorithm(arr) << std::endl;
  return 0;
}
