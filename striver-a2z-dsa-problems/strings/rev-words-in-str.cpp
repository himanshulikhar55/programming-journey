#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    string ans="", temp="";
    int start=0, end = s.size()-1;
    while(start <= end && s[start]==' ')
        start++;
    while(end>=start && s[end]==' ')
        end--;
    while(start <= end){
        if(s[start]!= ' '){
            temp += s[start];
            start++;
        } else {
            ans = temp + ans;
            while(start <= end && s[start]==' ')
                start++;
            if(start <= end)
                ans = ' ' + ans;
            temp = "";
        }
    }
    if(temp.size() > 0)
        ans = temp + ans;
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    s = reverseWords(s);
    cout << "After reversing the words and removing redundant spaces, the string is: " << s << ".\n";
    return 0;
}