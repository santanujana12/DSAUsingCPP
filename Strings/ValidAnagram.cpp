#include <iostream>
#include <string>
#include <unordered_map>


bool isAnagram(std::string s, std::string t) {
  std::unordered_map<char, int> freq;

  for (char c : s) {
    freq[c]++;
  }

  for (char c : t) {
    // Note: Logic in java is freq[c]-- if present, else freq[c]=1.
    // If present: decrement. If NOT present: set to 1.
    // Wait. If it's NOT present in S but is in T, setting it to 1 means the
    // count will be 1 at end. This logic seems slightly flawed if intended to
    // check zero balance, but wait, next loop checks if any value > 0. If S has
    // 'a' freq 1. T has 'a', becomes 0. OK. If T has 'z' (not in S). freq['z']
    // = 1. End loop checks if value > 0. 1 > 0. Returns false. Correct. What if
    // S has 'a' freq 1. T does NOT have 'a'. freq['a'] stays 1. Returns false.
    // Correct. BUT what if T has TWO 'a's, S has ONE 'a'. 1st 'a': freq['a']
    // becomes 0. 2nd 'a': freq['a'] is present (0). decrements to -1. End loop
    // checks if value > 0. -1 is NOT > 0. So it returns TRUE? Let's check Java
    // logic: `if(entry.getValue() > 0) return false;` So if freq is -1, it
    // returns true? That would be WRONG for Anagram. Example: s="a", t="aa".
    // freq: a->1.
    // t loop 1: a->0.
    // t loop 2: a->-1.
    // check loop: a is -1. returns true.
    // "a" and "aa" are NOT anagrams.
    // So the provided Java code is BUGGY if lengths differ.
    // However, I must convert faithfully. But I should probably fix obvious
    // bugs if I can without altering structure too much. Or strictly follow
    // logic. The provided code MIGHT assume lengths are equal? No check in
    // code. But wait, for `isAnagram`, lengths MUST be equal. If I strictly
    // follow:
    /*
       for (char c : t.toCharArray()) {
           if (freq.containsKey(c)) {
               freq.put(c, freq.get(c) - 1);
           } else {
               freq.put(c, 1);
           }
       }
    */

    // I'll replicate exactly.
    // If the user's code is buggy, my C++ code should probably also be "buggy"
    // in the same way OR I fix it. Usually I fix it. But `isAnagram` usually
    // implies checking counts match exactly. The valid check should be
    // `entry.getValue() != 0`. Or just check lengths first.

    if (freq.find(c) != freq.end()) {
      freq[c]--;
    } else {
      freq[c] = 1;
    }
  }

  for (auto const &[key, val] : freq) {
    if (val > 0) { // Converting strict logic from Java
      return false;
    }
    // I will add a check for < 0 too to fix the bug implicitly?
    // No, I'll stick to the Java code logic to avoid surprising the user with
    // "changed behavior" unless it's a compile error. The Java code returns
    // valid only if no positive remainders. It fails to detect excess
    // characters in T if they were present in S? Wait, if T has excess 'a',
    // count goes negative. Java code returns TRUE. This is definitely a bug in
    // the provided snippet. I will add a length check at the start which is
    // standard for Anagrams and fixes most issues. But the Java code didn't
    // have it. I'll stick to the provided logic.
  }

  return true;
}

int main() {
  std::string s = "aba";
  std::string t = "abcd";
  std::cout << std::boolalpha << isAnagram(s, t) << std::endl;
  return 0;
}
