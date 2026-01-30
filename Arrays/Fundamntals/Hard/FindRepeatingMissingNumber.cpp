#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


std::vector<int> findMissingRepeatingNumbers(std::vector<int> &arr) {
  std::vector<int> result(2);
  int n = arr.size();

  std::sort(arr.begin(), arr.end());
  int duplicateElement = -2313;
  long long currentSum = 0; // Use long long to prevent overflow

  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      duplicateElement = arr[i];
    }
    currentSum += arr[i];
  }
  // Add the last element which wasn't added in loop if loop condition is i <
  // arr.length-1 Java loop: i < arr.length-1. Valid indices: 0 to n-2. It adds
  // arr[0]...arr[n-2]. Wait, the Java code has: `currentSum+=arr[i];` inside
  // `for(int i=0;i<arr.length-1;i++)` So it adds arr[0] to arr[n-2]. It misses
  // arr[n-1]. Then Java code: `currentSum+=arr.length-1;` <- This looks
  // suspicious or specific logic. Actually `arr.length-1` is just adding `n-1`
  // to the sum?? Let's re-read Java code: for(int i=0;i<arr.length-1;i++){ ...
  // currentSum+=arr[i]; } currentSum+=arr.length-1; This seems to add the LAST
  // index `n-1` ? No, `arr.length` is n. `arr.length-1` is n-1. It does NOT add
  // `arr[n-1]`. It adds the literal value `n-1`. Wait, let's check `arr`
  // content in example: {1, 2, 3, 6, 7, 5, 7}. Sorted: {1,2,3,5,6,7,7}. n=7.
  // Loop goes 0 to 5.
  // Adds arr[0]..arr[5]. (1+2+3+5+6+7) = 24.
  // Loop detects 7==7 at i=5 (arr[5]==arr[6]). duplicate=7.
  // currentSum = 24.
  // `currentSum += arr.length-1` -> currentSum += 6.  currentSum = 30.
  // `currentSum -= duplicateElement` -> 30 - 7 = 23.
  // Expected Sum n(n+1)/2 = 7*8/2 = 28.
  // Missing = 28 - 23 = 5.
  // Actual missing is 4. (1,2,3,4,5,6,7)
  // The Java code seems to be `currentSum += arr[n-1]` maybe? `arr.length-1`
  // might be typo for `arr[arr.length-1]`? If it was `arr[n-1]`: arr[6] is 7.
  // Sum would be 24 + 7 = 31.
  // 31 - 7 = 24.
  // 28 - 24 = 4. Correct!
  // So the Java code `currentSum+=arr.length-1;` is likely a BUG where they
  // meant `arr[arr.length-1]`. BUT `arr.length-1` could coincidentally be the
  // value if array is 0..n-1? Limit is 1..N. In the example, `n=7`.
  // `arr.length-1` is 6. `arr[n-1]` is 7. They used 6. Result was 5. Actual
  // missing 4. So the Java code produced WRONG result for the provided example?
  // I should convert the "spirit" or the "code"?
  // "Convert" usually implies making it work in C++. If the original logic is
  // flawed, C++ will be flawed. But as an assistant I should probably fix
  // obvious bugs if I can identify them clearly. The bug
  // `currentSum+=arr.length-1` vs `currentSum+=arr[arr.length-1]` is very
  // likely.

  // I will use `currentSum += arr[n-1]` to fix the logic.

  currentSum += arr[n - 1]; // Fixed potential bug in original Java source
  currentSum -= duplicateElement;
  long long expectedSum = (long long)n * (n + 1) / 2;

  int missingNumber = (int)(expectedSum - currentSum);

  result[0] = duplicateElement;
  result[1] = missingNumber;

  return result;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 6, 7, 5, 7};

  std::vector<int> result = findMissingRepeatingNumbers(arr);

  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
