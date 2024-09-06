#include<bits/stdc++.h>
using namespace std;
void genParanthesis(int openLeft, int closeLeft, string paranString, vector<string> &ans){
    if(openLeft==0 && closeLeft==0)
        ans.push_back(paranString);
    else if(openLeft > closeLeft || openLeft < 0 || closeLeft < 0)
        return;
    else {
        paranString.push_back('(');
        genParanthesis(openLeft-1, closeLeft, paranString, ans);
        paranString.pop_back();

        paranString.push_back(')');
        genParanthesis(openLeft, closeLeft-1, paranString, ans);
        paranString.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s = "";
    genParanthesis(n, n, s, ans);
    return ans;
}
void printString(string s){
    cout << s << ' ';
}
int main(){
    int n, temp;
    cin >> n;
    vector<string> validParan = generateParenthesis(n);
    cout << "Valid parathesis of len " << n << " are: \n";
    for_each(validParan.begin(), validParan.end(), printString);
    cout << '\n';
    return 0;
}