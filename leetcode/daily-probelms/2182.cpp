/**
 * Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> charFreq = vector<int>(26,0);
        set<char> charSet;
        string finalString = "";
        for(char c : s){
            charFreq[c-'a']++;
            charSet.insert(c);
        }
        while(!charSet.empty()){
            char lastChar = *charSet.rbegin();
            bool lastCharDone = false;
            int freq = min(charFreq[lastChar-'a'], repeatLimit);
            charFreq[lastChar-'a'] -= freq;
            for(int i=0;i<freq;i++)
                finalString += lastChar;
            if(charFreq[lastChar-'a'] == 0){
                lastCharDone = true;
                charSet.erase(lastChar);
            }
            if(!lastCharDone){
                if(lastChar != *(++(charSet.rbegin()))){
                    lastChar = *(++(charSet.rbegin()));
                    cout << lastChar << '\n';
                    finalString += lastChar;
                    charFreq[lastChar-'a']--;
                    if(charFreq[lastChar-'a'] == 0)
                        charSet.erase(lastChar);
                } else {
                    break;
                }
            }
        }
        return finalString;
    }
};