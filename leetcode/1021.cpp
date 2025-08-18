#include<bits/stdc++.h>

std::string removeOuterParentheses(std::string s) {
    std::stack<char> st;
    int n = s.length(), start;
    std::string ans = "";
    for(int i=0;i<n;i++) {
        if(s[i] == '(') {
            if(st.empty())
                start = i;
            st.push(s[i]);
        } else {
            st.pop();
            if(st.empty()) {
                ans += s.substr(start+1, i-start-1);
            }
        }
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << removeOuterParentheses(s) << std::endl;
}