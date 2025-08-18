/*
Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:

    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

 

Example 1:

Input: s = "()"
Output: 1

Example 2:

Input: s = "(())"
Output: 2

Example 3:

Input: s = "()()"
Output: 2

Constraints:
    2 <= s.length <= 50
    s consists of only '(' and ')'.
    s is a balanced parentheses string.
*/

#include <bits/stdc++.h>

int scoreOfParentheses(std::string s) {
    std::stack<int> st;
    st.push(0);
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(s[i] == '(')
        st.push(0);
        else {
            int tempScore = st.top();
            st.pop();
            if(tempScore == 0)
            tempScore += 1;
            else
            tempScore <<= 1;
            st.top() += tempScore;
        }
        // std::cout << "Stack size: " << st.size() << std::endl;
    }
    return st.top();
}

int scoreOfParentheses2(std::string s) {
    int depth = 0, n = s.length();
    int ans = 0;
    char prev;
    for(int i=0;i<n; i++) {
        if(s[i] == '(')
            depth++;
        else {
            depth--;
            if(prev == '(')
                ans += std::pow(2, depth);
        }
        prev = s[i];
    }
    return ans;
}
int main() {
    std::string str;
    std::cin >> str;

    std::cout << scoreOfParentheses(str) << std::endl;
    std::cout << scoreOfParentheses2(str) << std::endl;
    return 0;
}