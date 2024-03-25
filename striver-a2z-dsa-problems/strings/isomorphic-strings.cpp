#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size())
        return false;
    unordered_map<char,char> map1, map2;
    string charSub="";
    int n = t.size();
    for(int i=0;i<n;i++){
        if((map1.find(s[i])==map1.end() && map2.find(t[i]) != map2.end()) ||
           (map1.find(s[i])!=map1.end() && map2.find(t[i]) == map2.end())){
            return false;
        } else {
            if(map1.find(s[i]) == map1.end()){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else{
                if(map1[s[i]] != t[i] ||
                   map2[t[i]] != s[i])
                    return false;
            }
        }
    }
    return true;
}
int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(isIsomorphic(s,t))
        cout << "The given strings are isomorphic\n";
    else
        cout << "The given strings are not isomorphic\n";
    return 0;
}