#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>


bool isAlphanumeric(char ch) { return std::isalnum(ch); }

bool isPalindrome(std::string s) {
  // lowercase the string
  std::string lowerS = "";
  for (char c : s) {
    lowerS += std::tolower(c);
  }

  std::string result = "";
  for (int i = 0; i < lowerS.length(); i++) {
    char ch = lowerS[i];
    if (isAlphanumeric(ch)) {
      result += ch;
    }
  }

  int n = result.length();
  for (int i = 0; i < n / 2; i++) {
    if (result[i] != result[n - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  std::string s = " ";
  std::cout << std::boolalpha << isPalindrome(s) << std::endl;
  return 0;
}
