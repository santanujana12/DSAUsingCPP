#include <iostream>
#include <string>
#include <vector>


int lengthOfLastWord(std::string s) {
  std::vector<std::string> resultList;
  int i = 0;
  while (i < s.length()) {
    if (s[i] == ' ') {
      i++;
    } else {
      std::string a = "";
      while (i < s.length() && s[i] != ' ') {
        a += s[i];
        i++;
      }
      resultList.push_back(a);
    }
  }
  if (!resultList.empty()) {
    return resultList.back().length();
  } else {
    return 0;
  }
}

int main() {
  std::string s = "luffy is still joyboy";
  std::cout << lengthOfLastWord(s) << std::endl;
  return 0;
}
