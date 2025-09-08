#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
int n, w;

long long solve(int pos, int wt_left, vector<int> &val, vector<int> &wt) {
    if(pos == n)
        return 0;
    
    if(dp[pos][wt_left] != -1) 
        return dp[pos][wt_left];
    
    long long not_take = solve(pos+1, wt_left, val, wt);
    
    long long take = 0;
    if(wt[pos] <= wt_left) {
        take = val[pos] + solve(pos+1, wt_left - wt[pos], val, wt);
    }
    
    return dp[pos][wt_left] = max(not_take, take);
}


int main() {
    cin >> n >> w;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++) {
        cin >> wt[i] >> val[i];
    }
    dp = vector<vector<long long>>(n+1, vector<long long>(w+1, -1));
    std::cout << solve(0, w, val, wt) << endl;
    return 0;
}