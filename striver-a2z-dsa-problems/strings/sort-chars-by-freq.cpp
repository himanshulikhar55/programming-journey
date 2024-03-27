#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    string ans="";
    vector<pair<int, char>> charMap(256, {0,0});
    int n=s.length();
    for(int i=0;i<n;i++){
        charMap[s[i]].second = s[i];
        ++(charMap[s[i]].first);
    }
    sort(charMap.begin(), charMap.end());
    for(int i=255;i>=0;i--){
        if(charMap[i].first > 0){
            for(int j=0;j<charMap[i].first;j++)
                ans += charMap[i].second;
        } else {
            break;
        }
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout << "After sorting the string based on frequency of chars: "<< frequencySort(s) << '\n';
    return 0;
}