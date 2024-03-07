#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int ans = 0, len = s.length();
    set<char> letters;
    for(int i=0;i<len;i++){
        ans = max(ans, (int)letters.size());
        letters.clear();
        letters.insert(s[i]);
        for(int j=i+1;j<len;j++){
            if(letters.find(s[j]) != letters.end())
                break;
            letters.insert(s[j]);
        }
    }
    ans = max(ans, (int)letters.size());
    return ans;
}
int main(){
    cout << "Enter a string: ";
    string s;
    cin >> s;
    cout << "The length of Longest Substring Without Repeating Characters is: " << lengthOfLongestSubstring(s) << '\n';
}