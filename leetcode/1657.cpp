/*
Two strings are considered close if you can attain one from the other using the following operations:

    Operation 1: Swap any two existing characters.
        For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and
                 do the same with the other character.
        For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

Constraints:
    1 <= word1.length, word2.length <= 10^5
    word1 and word2 contain only lowercase English letters.
*/
#include<bits/stdc++.h>

bool closeStrings(std::string word1, std::string word2) {
    if(word1.length() != word2.length())
        return false;
    std::vector<int> freqMap1(26), freqMap2(26);
    int n = word1.size();
    for(int i=0;i<n;i++) {
        freqMap1[word1[i]-'a']++;
        freqMap2[word2[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(freqMap1[i] != 0 && freqMap2[i] == 0)
            return false;
        if(freqMap1[i] == 0 && freqMap2[i] != 0)
            return false;
    }
    std::sort(freqMap1.begin(), freqMap1.end());
    std::sort(freqMap2.begin(), freqMap2.end());
    for(int i=0;i<26;i++) {
        if(freqMap1[i] != freqMap2[i])
            return false;
    }
    return true;
}

int main() {
    std::string a,b;
    std::cin >> a >> b;
    if(closeStrings(a, b))
        std::cout << "They are close!" << std::endl;
    else
        std::cout << "Oh no! They are NOT close!" << std::endl;
    return 0;
}
