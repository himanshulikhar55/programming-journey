#include <bits/stdc++.h>
using namespace std;
string mergeAlternately(string word1, string word2) {
    if(word1.length() < 1)
            return word2;
        if(word2.length() < 1)
            return word1;
        int len1 = word1.length(), len2 = word2.length(), min_len = min(len1, len2);
        string ans = "";
        for(int i=0;i<min_len;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(len1 < len2){
            ans += word2.substr(min_len,len2 - len1);
        }
        else if(len2 < len1){
            ans += word1.substr(min_len, len1 - len2);
        }
        return ans;
}
int main(){
    string s1,s2;
    cout << "Insert the 1st string: ";
    cin >> s1;
    cout << "Insert the 2nd string: ";
    cin >> s2;
    cout << "Alternately merged string is: " << mergeAlternately(s1,s2) << '\n';
}