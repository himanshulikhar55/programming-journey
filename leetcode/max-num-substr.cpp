#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dict;
int max_num_subs(string &s, int start_pos){
    /* Base case */
    if(start_pos == s.length())
        return 0;
    int ret_val = -1;
    /* i = size of substr */
    for(int i=1; i+start_pos<=s.length();i++){
        string temp = s.substr(start_pos, i);
        /* if this substring is not there */
        if(dict.find(temp) == dict.end()){
            dict.insert(temp);
            /* find max num of splits when this substring is considered */
            int val = max_num_subs(s, start_pos+i);
            if(val >= 0)
                ret_val = max(val+1, ret_val);
            /* erase it to make way for next combination */
            dict.erase(temp);
        }
    }
    return ret_val;
}
int maxUniqueSplit(string s) {
    return max_num_subs(s, 0);
}
int main(){
    string s;
    cin >> s;
    cout << maxUniqueSplit(s) << endl;
    return 0;
}