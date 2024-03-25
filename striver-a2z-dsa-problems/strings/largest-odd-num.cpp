#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string s) {
    int n=s.size()-1, i;
    for(i=n;i>=0;i--)
        if((s[i]-'0')%2)
            break;
    if(i==-1)
        return "";
    return s.substr(0, i+1);
}
int main(){
    string s;
    getline(cin, s);
    s = largestOddNumber(s);
    cout << "The larges odd num in the given string is: " << s << ".\n";
    return 0;
}