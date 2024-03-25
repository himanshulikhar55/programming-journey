#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
    stack<char> st;
    string op = "";
    for(char c : s){
        if(c == '('){
            if(!st.empty())
                op += c;
            st.push(c);
        } else {
            //it is given that the input string will be valid
            if(st.size() > 1)
                op += c;
            st.pop();
        }
    }
    return op;
}
int main(){
    string s;
    getline(cin, s);
    s = removeOuterParentheses(s);
    cout << "After removing the outer paranthesis, the string is: " << s << '\n';
    return 0;
}