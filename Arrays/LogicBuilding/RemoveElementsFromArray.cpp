#include <bits/stdc++.h>
using namespace std;

int removeElement(std::vector<int> &arr, int val) {
  int first = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != val) {
      arr[first] = arr[i];
      first++;
    }
  }
  return first;
}

int main() {
  vector<int> arr = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int removedArrSize = removeElement(arr, val);

  for (int i = 0; i < removedArrSize; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
