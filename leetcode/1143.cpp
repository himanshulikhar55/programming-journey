/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/
#include <bits/stdc++.h>

std::vector<std::vector<int>> dp;

int lcs(std::string &str1, std::string &str2, int i, int j) {
    if(i==str1.length())
        return 0;
    if(j == str2.length())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str1[i] == str2[j])
        return dp[i][j] = 1 + lcs(str1, str2, i+1, j+1);
    return dp[i][j] = std::max(lcs(str1, str2, i+1, j), std::max(lcs(str1, str2, i, j+1),
                                                          lcs(str1, str2, i+1, j+1)));
}

int longestCommonSubsequence(std::string text1, std::string text2) {
    dp = std::vector<std::vector<int>>(text1.length()+1, std::vector<int>(text2.length()+1, -1));
    return lcs(text1, text2, 0, 0);
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << longestCommonSubsequence(s,t) << std::endl;
}