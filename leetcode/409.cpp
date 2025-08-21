/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:
    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.

*/

#include<bits/stdc++.h>

int longestPalindrome(std::string s) {
    int freqMap[256], longestPalSize = 0;
    int maxOdd = 0;
    memset(freqMap, 0, 256 * sizeof(int));
    for(char &c : s) {
        freqMap[c]++;
    }
    for(int i : freqMap) {
        if(i%2) {
            longestPalSize += i-1;
            maxOdd = i;
        } else if(i%2 == 0) {
            longestPalSize += i;
        }
    }
    if(maxOdd > 0)
        ++longestPalSize;
    return longestPalSize;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << longestPalindrome(s) << std::endl;
    return 0;
}