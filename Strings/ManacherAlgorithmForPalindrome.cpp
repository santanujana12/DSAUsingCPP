#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findLongestPalindrome(string originalInput) {
    // 1. Transform: "aba" -> "@#a#b#a#$" 
    // This handles both even and odd length palindromes.
    string modifiedString = "@";
    for (char character : originalInput) {
        modifiedString += "#" + string(1, character);
    }
    modifiedString += "#$";

    int totalLength = modifiedString.length();
    vector<int> radii(totalLength, 0); 
    int mainCenter = 0;
    int rightBoundary = 0;

    for (int i = 1; i < totalLength - 1; i++) {
        // Find the "mirror image" of our current position 'i'
        int mirrorPosition = 2 * mainCenter - i;

        // Step 1: Optimization - Use the mirror's data to avoid re-work
        if (i < rightBoundary) {
            radii[i] = min(rightBoundary - i, radii[mirrorPosition]);
        }

        // Step 2: Attempt to expand outward from index i
        while (modifiedString[i + (1 + radii[i])] == modifiedString[i - (1 + radii[i])]) {
            radii[i]++;
        }

        // Step 3: If this new palindrome reaches further right, update our records
        if (i + radii[i] > rightBoundary) {
            mainCenter = i;
            rightBoundary = i + radii[i];
        }
    }

    // 2. Identify the longest palindrome found
    int maxRadius = 0;
    int bestCenterIndex = 0;
    for (int i = 1; i < totalLength - 1; i++) {
        if (radii[i] > maxRadius) {
            maxRadius = radii[i];
            bestCenterIndex = i;
        }
    }

    // 3. Convert back to original string coordinates
    int startIndex = (bestCenterIndex - maxRadius) / 2;
    return originalInput.substr(startIndex, maxRadius);
}

int main() {
    string input = "babad";
    cout << "Longest Palindrome: " << findLongestPalindrome(input) << endl;
    return 0;
}
