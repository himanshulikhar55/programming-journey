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
int main(){
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    cout << "The number of substrings with " << k << " distinct chars is: " << countSubStrings(s, k) << "\n";
    return 0;
}