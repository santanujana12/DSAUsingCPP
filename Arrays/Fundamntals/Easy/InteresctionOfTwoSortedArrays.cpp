#include <bits/stdc++.h>
using namespace std;

// Unoptimized approach
vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2) {
  vector<int> result;
  vector<int> visited(arr2.size(), 0);

  for (int i = 0; i < arr1.size(); i++) {
    for (int j = 0; j < arr2.size(); j++) {
      if (arr1[i] == arr2[j] && visited[j] == 0) {
        result.push_back(arr1[i]);
        visited[j] = 1;
        break;
      }
    }
  }
  return result;
}

// Optimized approach
vector<int> findIntersectionOptimized(vector<int> &arr1, vector<int> &arr2) {
  vector<int> result;
  int i = 0, j = 0;

  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      i++;
    } else if (arr1[i] > arr2[j]) {
      j++;
    } else {
      result.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  return result;
}

int main() {
  vector<int> arr1 = {-45, -45, 0, 0, 2};
  vector<int> arr2 = {-50, -45, 0, 0, 5, 7};

  vector<int> result = findIntersectionOptimized(arr1, arr2);

  for (int item : result) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
