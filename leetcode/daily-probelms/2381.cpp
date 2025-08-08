#include <bits/stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> prefix = vector<int>(s.length()+1, 0);
    int n = shifts.size();
    for(int i=0;i<n;i++){
        if(shifts[i][2]){
            prefix[shifts[i][0]]++;
            prefix[shifts[i][1]+1]--;
        } else {
            prefix[shifts[i][0]]--;
            prefix[shifts[i][1]+1]++;
        }
    }
    n = s.length();
    for(int i=1;i<=n;i++)
        prefix[i] += prefix[i-1];
    for(int i=0;i<n;i++){
        int num = s[i]-'a';
        if(prefix[i] >= 0){
            num = (num+prefix[i])%26;
        } else {
            prefix[i] = prefix[i]%26;
            if(num < abs(prefix[i])){
                num += 26 + prefix[i];
            } else {
                num += prefix[i];
            }
        }
        s[i] = 'a'+num;
    }
    return s;
}
int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int n;
    cout << "Enter the number of shifts: ";
    cin >> n;
    vector<vector<int>> shifts;
    for(int i=0;i<n;i++){
        vector<int> temp = vector<int>(3, 0);
        cin >> temp[0] >> temp[1] >> temp[2];
        shifts.push_back(temp);
    }
    cout << "Final string: " << shiftingLetters(s, shifts) << '\n';
    return 0;
}