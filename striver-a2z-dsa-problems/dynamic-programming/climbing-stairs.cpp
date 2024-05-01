#include<bits/stdc++.h>
using namespace std;
/*
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
int climbStairs(int n) {
    vector<int> dp = vector<int>(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;
    cout << "The number of ways I can climb " << n << " stairs is: " << climbStairs(n) << '\n';
    return 0;
}