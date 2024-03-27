#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    int n=s.length();
    vector<int> sMap(27,0), tMap(27,0);
    for(int i=0;i<n;i++){
        ++sMap[s[i]-'a'];
        ++tMap[t[i]-'a'];
    }
    for(int i=0;i<26;i++)
        if(sMap[i]!=tMap[i])
            return false;
    return true;
}
int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(isAnagram(s,t))
        cout << s << " is an anagram of "<< t << "\n";
    else
        cout << s << " is not an anagram of "<< t << "\n";
    return 0;
}