#include<bits/stdc++.h>

bool isOpen(char c) {
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isValid(std::string s) {
    std::stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(isOpen(s[i]))
            st.push(s[i]);
        else if(s[i] == ']') {
            if(st.empty() || st.top() != '[')
                return false;
            st.pop();
        } else if(s[i] == '}') {
            if(st.empty() || st.top() != '{')
                return false;
            st.pop();
        } else if (s[i] == ')') {
            if(st.empty() || st.top() != '(')
                return false;
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    std::string s;
    std::cin >> s;
    if(isValid(s))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Not Valid" << std::endl;
    return 0;
}