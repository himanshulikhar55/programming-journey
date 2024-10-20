#include <bits/stdc++.h>

bool is_op(char c){
    return c == '!' || c == '|' || c == '&';
}

char eval_expr(std::string s, char op){
    if(op == '!'){
        if(s == "t")
            return 'f';
        else
            return 't';
    } else if(op == '|'){
        if(s.find('t') != std::string::npos)
            return 't';
        else
            return 'f';
    } else if(op == '&'){
        if(s.find('f') != std::string::npos)
            return 'f';
        else
            return 't';
    }
    return 'f';
}
bool parseBoolExpr(std::string expression) {
    std::stack<char> st;
    std::string curr_expr = "";
    char c;
    for(int i=0;i<expression.length();i++){
        c = expression[i];
        if(c==',' || c == '(')
            continue;
        else if(c == ')'){
            while(!st.empty() && !is_op(st.top())){
                curr_expr += st.top();
                st.pop();
            }
            char op = st.top();
            st.pop();
            if(op == '!'){
                st.push(eval_expr(curr_expr, '!'));
            } else if(op == '|'){
                st.push(eval_expr(curr_expr, '|'));
            } else if(op == '&'){
                st.push(eval_expr(curr_expr, '&'));
            }
            curr_expr = "";
        } else if(is_op(c)){
            for(char c : curr_expr)
                st.push(c);
            st.push(c);
            curr_expr = "";
        } else {
            curr_expr += c;
        }
    }
    return st.top() == 't';
}

int main(){
    std::string s;
    std::cin >> s;
    if(parseBoolExpr(s))
        std::cout << s << " evaluates to true\n";
    else
        std::cout << s << " evaluates to false\n";
}