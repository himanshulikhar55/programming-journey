#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==1)
        return strs[0];
    string ans=strs[0];
    int n = strs.size(), j, minLen;
    for(int i=1;i<n;i++){
        j=0;
        minLen = min(strs[i].size(), ans.size());
        while(j<minLen && strs[i][j] == ans[j])
            j++;
        if(j==0)
            return "";
        ans = ans.substr(0,j);
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    vector<string> words;
    stringstream ss(s);
    string word;
    // Split the string into words
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
    s = longestCommonPrefix(words);
    cout << "The longest common prefix is: " << s << ".\n";
    return 0;
}