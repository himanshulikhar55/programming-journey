#include<bits/stdc++.h>
using namespace std;
/*
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

    The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.
*/
bool checkValidString(string s) {
    int maxOpen = 0, minOpen = 0, n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            maxOpen++;
            minOpen++;
        }
        else if(s[i] == ')'){
            maxOpen--;
            if(minOpen)
                minOpen--;
        }
        else {
            maxOpen++;
            if(minOpen)
                minOpen--;
        }
        if(maxOpen < 0)
            return false;
    }
    return minOpen == 0;
}
int main(){
    string s;
    cin >> s;
    if(checkValidString(s))
        cout << "Yes, the string is a valid paranthesis :)\n";
    else
        cout << "No, the string is not a valid paranthesis :(\n";
    return 0;
}