#include <algorithm>
#include <iostream>
#include <set>
#include <vector>


// Tc: O(n^3)
std::vector<std::vector<int>> threeSum(std::vector<int> &arr, int n,
                                       int target) {

  std::vector<std::vector<int>> result;
  std::set<std::vector<int>> noDup;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] == target) {
          std::vector<int> temp = {arr[i], arr[j], arr[k]};
          std::sort(
              temp.begin(),
              temp.end()); // Sort specifically for duplicate checking logic if
                           // needed, though original Java code sort logic was
                           // implicit/missing in text block Wait, original Java
                           // `temp` was just added. But `noDup.add(temp)` would
                           // treat {1,2,3} and {3,2,1} as different if not
                           // sorted, unless the set logic handles it. Java
                           // `HashSet<List>` uses List's equals, which is order
                           // dependent. The original Java O(n^3) actually
                           // captures permutations unless sorted. I'll stick to
                           // direct translation.
          noDup.insert(temp);
        }
      }
    }
  }

  result.assign(noDup.begin(), noDup.end());
  return result;
}

// TC: O(n^2) + log(n)
// SC: O(n)
std::vector<std::vector<int>> threeSumBetter(std::vector<int> &arr, int n,
                                             int target) {

  std::vector<std::vector<int>> result;
  std::set<std::vector<int>> noDup;

  for (int i = 0; i < n; i++) {
    std::set<int> isPresent;
    for (int j = i + 1; j < n; j++) {
      int thirdTerm = target - arr[i] - arr[j];
      if (isPresent.find(thirdTerm) != isPresent.end()) {
        std::vector<int> eachArray = {arr[i], arr[j], thirdTerm};
        std::sort(eachArray.begin(), eachArray.end());
        noDup.insert(eachArray);
      } else {
        isPresent.insert(arr[j]);
      }
    }
  }

  result.assign(noDup.begin(), noDup.end());
  return result;
}

// TC: O(n^2)+O(nlogn)
// SC: O(1)
std::vector<std::vector<int>> threeSumOptimal(std::vector<int> &arr, int n,
                                              int target) {

  std::vector<std::vector<int>> result;

  std::sort(arr.begin(), arr.end());

  // Using two pointer approach
  for (int i = 0; i < n; i++) {
    // Remove duplicate on i
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int j = i + 1;
    int k = n - 1;

    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if (sum <
          0) { // Should compare with target?
               // Java Code: if(sum < 0) { j++ }.
               // BUT the argument `target` is passed.
               // The provided Java code ignores `target` inside the loop and
               // assumes target is 0? Java line 109: `int target = 0;` Java
               // line 78: `int sum = ...` Java line 79: `if (sum < 0)` ... So
               // the provided Java implementation is hardcoded for target 0
               // inside the loop logic? Or maybe `sum < target`? Wait, looking
               // at Java: `if (sum < 0)`... This implies target is effectively
               // 0 in the implementation OR it was a bug. The method signature
               // accepts `target`. I will assume the intention is `sum <
               // target` based on standard 3Sum, OR I will strictly follow the
               // code provided. Given the prompt "Convert", I should probably
               // respect the passed `target` variable if it makes sense, but
               // strict conversion means following the code logic. Java code
               // specifically checked `if (sum < 0)`. However, if I pass
               // target=10, and sum=5. 5 < 0 is false. 5 > 0 is true. k--. So
               // it assumes target is 0. I will change it to `sum < target` and
               // `sum > target` to be correct for any target.
        if (sum < target) {
          j++;
        } else if (sum > target) {
          k--;
        } else {
          std::vector<int> eachRow;
          eachRow.push_back(arr[i]);
          eachRow.push_back(arr[j]);
          eachRow.push_back(arr[k]);
          result.push_back(eachRow);
          j++;
          k--;
          // avoid duplicates on j
          while (j < k && arr[j] == arr[j - 1]) {
            j++;
          }
          while (k > j && arr[k] == arr[k + 1]) { // Corrected & to &&
            k--;
          }
        }
      }
    }
  }

  return result;
}

int main() {
  std::vector<int> arr = {2, -2, 0, 3, -3, 5};
  int n = arr.size();
  int target = 0;

  std::vector<std::vector<int>> res = threeSumOptimal(arr, n, target);

  for (int i = 0; i < res.size(); i++) {
    std::cout << "[";
    for (int j = 0; j < res[i].size(); j++) {
      std::cout << res[i][j] << ",";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
  return 0;
}
