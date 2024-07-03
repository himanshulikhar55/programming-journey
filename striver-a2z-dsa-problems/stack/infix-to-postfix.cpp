#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    //'('
    return 0;
}
string infixToPostfix(string s) {
    int len = s.length();
    if(len < 2)
        return s;
    string ans = "";
    stack<char> operators;
    char c;
    for(int i=0;i<len;i++){
        cout << ans << '\n';
        c = s[i];
        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9')){
            ans += c;
        } else if(c == '(') {
            operators.push(c);
        } else if(c == ')'){
            while(operators.top() != '('){
                ans += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while(operators.size() > 0 &&
                 (precedence(c) <= precedence(operators.top()))){
                ans += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while(operators.size() > 0){
        ans += operators.top();
        operators.pop();
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    string ans = infixToPostfix(s);
    cout << "After converting the infix string " << s << " to postfix we get: \n";
    cout << ans;
    return 0;
}