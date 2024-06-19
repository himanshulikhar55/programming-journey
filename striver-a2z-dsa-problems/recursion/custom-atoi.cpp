
#include<bits/stdc++.h>
using namespace std;
/*
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

    The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
    If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range.
    Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
    Return the integer as the final result.

    Constraints:

    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
int myAtoi(string s) {
    long ans = 0;
    int i = 0, len = s.length();
    bool isNeg = false;
    while(i<len && s[i] == ' '){
        ++i;
    }
    if(i<len){
        if(s[i] == '-'){
            isNeg = true;
            ++i;
        } else if(s[i] == '+'){
            isNeg = false;
            ++i;
        }
    }
    if(i>=len)
        return ans;
    int digit = s[i]-'0';
    while(i<len && digit >= 0 && digit <= 9){
        ans = ans*10;
        ans += digit;
        if(ans > INT_MAX){
            if(isNeg)
                return INT_MIN;
            return INT_MAX;
        }
        ++i;
        if(i<len)
            digit = s[i]-'0';
    }
    if(isNeg)
        return -ans;
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    int ans = myAtoi(s);
    cout << "The string converted to integer is: " << ans << '\n';
    return 0;
}