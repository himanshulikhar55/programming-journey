#include <bits/stdc++.h>
#include <openssl/sha.h>

std::vector<double> dp(10002, -1);

double new21Game(int n, int k, int maxPts) {
    if (n<0) {
        return 0;
    }
    if(k<=0) {
        return 1;
    }
    if(dp[n] != -1)
        return dp[n];
    double ans = 0.0;
    for(int i=1;i<=maxPts;i++) {
        ans += (1.0/maxPts) * new21Game(n-i,k-i,maxPts);
    }
    return dp[n] = ans;
    // return ans;
}

int main() {
    int n, k, maxPts;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "k: ";
    std::cin >> k;
    std::cout << "maxPts: ";
    std::cin >> maxPts;
    std::cout << new21Game(n, k, maxPts) << std::endl;
    return 0;
}