#include <bits/stdc++.h>

bool isIsomorphic(std::string s, std::string t) {
    if(s.length() != t.length())
        return false;
    std::vector<int> charMap(256);
    std::vector<int> revCharMap(256);

    int n = s.length();
    for(int i=0;i<n;i++) {
        if(charMap[s[i]] != revCharMap[t[i]])
            return false;
        charMap[s[i]]    = i+1;
        revCharMap[t[i]] = i+1;
    }
    std::sort(s.begin(), s.end());
    return true;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << isIsomorphic(s, t) << std::endl;
}