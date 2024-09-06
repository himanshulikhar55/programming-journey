#include<bits/stdc++.h>
using namespace std;
int findSubStr(string str, int k){
    vector<int> charMap(26,0);
    int ans=0, len = str.length(), start=0, end=0, index, charsInSubStr=0;
    while (end < len) {
        index = str[end]-'a';
        ++charMap[index];
        if(charMap[index] == 1)
            ++charsInSubStr;
        while (charsInSubStr > k) {
            --charMap[str[start]-'a'];
            if (charMap[str[start]-'a'] == 0) {
                --charsInSubStr;
            }
            ++start;
        }
        ans += end - start + 1;
        ++end;
    }
    // cout << '\n';
    return ans;
}
int countSubStrings(string str, int k) 
{
    return findSubStr(str, k) - findSubStr(str, k-1);
}
int findLen(string s, int start, int end){
    int len = s.length();
    while(start>=0 && end<len && s[start]==s[end]){
        ++end;
        --start;
    }
    return end-start-1;
}
//baaab
string longestPalindrome(string s) {
    if(s.length() < 2)
        return s;
    int len=s.length(), maxLen = 1, oddPalLen, evenPalLen, currMaxLen=1, start=0;
    for(int i=0;i<len;i++){
        oddPalLen = findLen(s,i,i);
        evenPalLen = findLen(s,i,i+1);
        currMaxLen = max(oddPalLen, evenPalLen);
        if(maxLen < currMaxLen){
            maxLen = currMaxLen;
            start = i-(maxLen-1)/2;
        }
    }
    return s.substr(start, maxLen);
}
int main(){
    string s;
    getline(cin, s);
    cout << "The longest palindromic substring in " << s << " is: " << longestPalindrome(s) << "\n";
    return 0;
}