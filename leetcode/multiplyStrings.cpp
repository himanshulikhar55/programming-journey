#include <bits/stdc++.h>
using namespace std;
string multiplyStringAndChar(string a, char c){
    if(c == '1')
        return a;
    int i, j = c-'0', res, len = a.length(), k=len, carry=0;
    string ans="";
    for(int l=len-1; l>=0; l--){
        i = a[l] - '0';
        res = (i*j) + carry;
        ans = to_string('0' + (res % 10)) + ans;
        cout << to_string('0' + (res % 10)) << ' ' << ans << ' ';
        carry = res / 10;
    }
    if(carry != 0)
        ans = to_string('0' + (carry)) + ans;
    cout << '\n';
    return string(ans);
}
string addStrings(string str1, string str2){
    if(str1.length() < str2.length())
        return addStrings(str2, str1);
    int len2 = str2.length(), len1 = str1.length(), i = len1 - 1, j = len2 - 1;
    int res = 0, carry = 0, k = len2;
    string ans="";
    while(i>=0 || j >=0){
        if(j>=0){
            res = (str1[i] - '0') + (str2[j] - '0') + carry;
            carry = res / 10;
            ans = to_string('0' + (res%10)) + ans;
        } else {
            res = (str1[i] - '0') + carry;
            carry = res/10;
            ans = to_string('0' + (res%10)) + ans;
        }
        i--; j--;k--;
    }
    if(carry != 0)
        ans = to_string('0' + (carry)) + ans;
    return ans;
}
string multiplyStrings(string a , string b ){
    //Write your code here
    if(a.length() < b.length())
        return multiplyStrings(b, a);
    string finalAns="", multiplier = "", tempNum = "";
    for(int i=b.length()-1; i>=0; i--){
        tempNum = multiplyStringAndChar(a, b[i]);
        tempNum += multiplier;
        cout << tempNum << ' ' << finalAns << '\n';
        finalAns = addStrings(finalAns, tempNum);
        multiplier += "0";
    }
    return finalAns;
}
int main(){
    string a,b;
    // char c = '0';
    // char d = '0' + 0;
    // cout << c << ' ' << d << 'a' << '\n';
    getline(cin, a);
    getline(cin, b);
    cout << a << ' ' << b << '\n';
    cout << multiplyStrings(a,b) << '\n';
    return 0;
}