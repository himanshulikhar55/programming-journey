#include<bits/stdc++.h>
using namespace std;

/*
    Read about this genuis yet simple approach. F!@# this is elegant.
*/

string findDifferentBinaryString(vector<string> &binStrings){
    string ans = "";
    //In this way the ith character in ans will be different from ith character of ith string. Hence it will
    //not be same as any string.
    for(int i=0;i<binStrings.size();i++){
        ans += (binStrings[i][i] == '0' ? "1" : "0");
    }
    return ans;
}
int main(){
    int n, temp;
    cin >> n;
    vector<string> binStrings = vector<string>(n);
    for(int i=0;i<n;i++){
        cin >> binStrings[i];
    }
    string missingBinString = findDifferentBinaryString(binStrings);
    cout << "One of the missing binary string is: " << missingBinString << '\n';
    return 0;
}