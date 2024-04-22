#include<bits/stdc++.h>
using namespace std;

void genBinStrings(vector<string> &binStrings, int n){
    if(n>0){
        if(binStrings.size() == 0){
            binStrings.push_back("0");
            binStrings.push_back("1");
        } else {
            int n = binStrings.size();
            for(int i=0;i<n;i++){
                binStrings.push_back("1" + binStrings[i]);
                binStrings[i] = "0" + binStrings[i];
            }
        }
        genBinStrings(binStrings, n-1);
    }
}
void printBinNum(string s){
    cout << s << ' ';
}
int main(){
    int n, temp;
    cin >> n;
    vector<string> binStrings;
    genBinStrings(binStrings, n);
    for_each(binStrings.begin(), binStrings.end(), printBinNum);
    cout << '\n';
    return 0;
}