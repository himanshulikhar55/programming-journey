/**
 * Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/
 */
#include <bits/stdc++.h>
bool canMakeSubsequence(std::string str1, std::string str2) {
    if(str2.length() > str1.length()){
        return false;
    }
    int i = 0, j = 0, len1 = str1.length(), len2 = str2.length();
    while(i<len1 && j<len2){
        if(str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 == str2[j] - 'a'){
            ++j, ++i;
        } else {
            ++i;
        }
    }
    if(j == len2){
        return true;
    }
    return false;
}
int main(){
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if(canMakeSubsequence(s1, s2)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}