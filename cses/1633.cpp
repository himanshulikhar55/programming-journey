#include <bits/stdc++.h>

#define MOD 1000000007

std::vector<int> dp;

int countWays(int n) {
    if(n==0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    int m = std::min(n, 6);
    for(int i=1;i<=m;i++) {
        ans = (ans+countWays(n-i)%MOD)%MOD;
    }
    return dp[n] = ans;
}

int main() {
    int n;
    std::cin >> n;
    dp = std::vector<int>(n+1, -1);
    std::cout << countWays(n) << std::endl;
    return 0;
}