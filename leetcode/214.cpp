/*
You are given a string s. You can convert s to a

by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: s = "abcd"
Output: "dcbabcd"

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of lowercase English letters only.

*/
#include<bits/stdc++.h>

std::vector<int> computeLPS(std::string s) {
    std::vector<int> lps(s.length());
    int i=1, j=0, n=s.length();
    while(i < n) {
        if(s[i] == s[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if(j!=0)
                j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

std::string shortestPalindrome(std::string s) {
    std::string reverseStr = std::string(s.rbegin(), s.rend());
    std::string compositeStr = s + "*" + reverseStr;
    std::vector<int> lps = computeLPS(compositeStr);

    return reverseStr.substr(0, s.length()-lps.back()) + s;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << shortestPalindrome(s) << std::endl;
    return 0;
}