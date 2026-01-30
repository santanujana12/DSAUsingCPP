#include <iostream>
#include <vector>

void mergeArrays(std::vector<int> &nums1, int m, std::vector<int> &nums2,
                 int n) {
  int pointer_a = m - 1;
  int pointer_b = n - 1;
  for (int i = m + n - 1; i >= 0; i--) {
    // Must check if pointer_b is valid first to avoid OOB if pointer_a is
    // exhausted Logic from java: if (pointer_a >= 0 && (pointer_b < 0 ||
    // nums1[pointer_a] >= nums2[pointer_b])) If pointer_b < 0, then we just
    // take from A. If pointer_b >= 0 and A >= B, take from A.
    if (pointer_a >= 0 &&
        (pointer_b < 0 || nums1[pointer_a] >= nums2[pointer_b])) {
      nums1[i] = nums1[pointer_a];
      pointer_a--;
    } else if (pointer_b >= 0) { // removed unnecessary condition check logic if
                                 // covered above
      // && nums2[pointer_b] >= nums1[pointer_a] -- this is implicit if the
      // first if failed? Not necessarily. If pointer_a < 0, first if fails.
      // Then we must take from B. If pointer_b >= 0 and nums1[a] < nums2[b],
      // first if fails. We take from B.
      nums1[i] = nums2[pointer_b];
      pointer_b--;
    }
  }
}

int main() {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;
  mergeArrays(nums1, m, nums2, n);
  for (int i : nums1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
