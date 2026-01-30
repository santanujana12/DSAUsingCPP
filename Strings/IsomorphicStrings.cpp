#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }

  std::unordered_map<char, char> mappedS;
  std::unordered_map<char, char> mappedT;

  for (int i = 0; i < s.length(); i++) {
    char charS = s[i];
    char charT = t[i];

    if (mappedS.find(charS) != mappedS.end()) {
      if (mappedS[charS] != charT) {
        return false;
      }
    } else {
      mappedS[charS] = charT;
    }

    if (mappedT.find(charT) != mappedT.end()) {
      if (mappedT[charT] != charS) {
        return false;
      }
    } else {
      mappedT[charT] = charS;
    }
  }

  return true;
}

int main() {
  std::string s = "egg";
  std::string t = "add";
  std::cout << std::boolalpha << isIsomorphic(s, t) << std::endl;
  return 0;
}
