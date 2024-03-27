#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) {
    if(s.length() != goal.length())
        return false;
    s = s+s;
    int len = s.length(), goalLen = goal.length(), i=0, j=0;
    while(i<len){
        if(s[i]==goal[j]){
            ++i;
            ++j;
            if(j==goalLen)
                return true;
        } else {
            if(j==0)
                ++i;
            else {
                i=i-j+1;
                j=0;
            }
        }
    }
    return false;
}
int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(rotateString(s,t))
        cout << s << " can be obtained by rotating "<< t << "\n";
    else
        cout << s << " cannot be obtained by rotating "<< t << "\n";
    return 0;
}