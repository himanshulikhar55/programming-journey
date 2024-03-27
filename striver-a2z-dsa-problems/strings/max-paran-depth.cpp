
#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
    stack<char> paran;
    int ans = 0;
    for(char c : s){
        if(c=='('){
            paran.push('(');
        } else if (c==')'){
            ans = max(ans, (int)paran.size());
            paran.pop();
        }
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout << "The maximum depth of paranthesis is: "<< maxDepth(s) << '\n';
    return 0;
}
// sample input: (1+(2*3)+((8)/4))+1
// Also, given that the input string is balanced