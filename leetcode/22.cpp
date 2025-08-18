#include <bits/stdc++.h>
bool balancedParenthesis(std::string str) {
    std::stack<char> st;
    st.push(str[0]);
    int n = str.length();
    for(int i=1;i<n;i++) {
        if(str[i] == ')') {
            if (st.empty())
                return false;
            if(st.top() != '(')
                return false;
            st.pop();
        } else {
            st.push(str[i]);
        }
    }
    return st.empty();
}
void _generateParenthesis(int n, std::vector<std::string> &ans, std::string str) {
    if(str.length() == (2 * n)) {
        if(balancedParenthesis(str)) {
            ans.push_back(str);
        }
        return;
    }
    _generateParenthesis(n, ans, str + '(');
    _generateParenthesis(n, ans, str + ')');
}
std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    _generateParenthesis(n, ans, "(");
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> ans = generateParenthesis(n);
    for(std::string s : ans) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
    return 0;
}