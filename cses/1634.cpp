#include <bits/stdc++.h>

#define MOD 1000000007

std::vector<int> dp;

// gives tle
// int countWays(std::vector<int> &coins, int target) {
//     if(target==0)
//         return 0;
//     if(dp[target] != -1)
//         return dp[target];
//     int ans = INT_MAX, n=coins.size();
//     for(int i=0;i<n;i++) {
//         if(coins[i] <= target) {
//             int ways = countWays(coins, target-coins[i]);
//             if(ways == -1)
//                 continue;
//             ans = std::min(ans, 1+ways);
//         }
//     }
//     if(ans == INT_MAX)
//         return -1;
//     return dp[target] = ans;
// }
#define INF 1e9

int countWays(std::vector<int> &coins, int target) {
    int n=coins.size();
    dp[0] = 0;
    for(int i=1;i<=target;i++) {
        for(int j=0;j<n;j++) {
            if(coins[j] > i || dp[i-coins[j]] == INF)
                continue;
            dp[i] = std::min(dp[i], 1+dp[i-coins[j]]);
        }
    }
    if(dp[target] == INF)
        return -1;
    return dp[target];
}

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> coin(n);
    for(int i=0;i<n;i++)
        std::cin >> coin[i];
    dp = std::vector<int>(target+1, INF);
    std::cout << countWays(coin, target) << std::endl;
    return 0;
}