/*
You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:

    pour 100 mL from type A and 0 mL from type B
    pour 75 mL from type A and 25 mL from type B
    pour 50 mL from type A and 50 mL from type B
    pour 25 mL from type A and 75 mL from type B

Note:

    There is no operation that pours 0 mL from A and 100 mL from B.
    The amounts from A and B are poured simultaneously during the turn.
    If an operation asks you to pour more than you have left of a soup, pour all that remains of that soup.

The process stops immediately after any turn in which one of the soups is used up.

Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.

Constraints: 0 <= n <= 10^9
*/
#include<bits/stdc++.h>
std::vector<std::vector<double>> dp = std::vector<std::vector<double>>(4802, std::vector<double>(4802,-1));
double solve(int a, int b){
    if(a==0 && b!=0)
        return 1;
    if(b==0 && a!=0)
        return 0;
    else if(a==0 && b==0)
        return 0.5;
    if(dp[a][b] != -1.0)
        return dp[a][b];
    double ans = 0;
    ans += 0.25 * (solve(std::max(a-100, 0), b) +
                   solve(std::max(a-75, 0), std::max(b-25, 0)) +
                   solve(std::max(a-50, 0), std::max(b-50, 0)) +
                   solve(std::max(a-25, 0), std::max(b-75, 0)));
    dp[a][b] = ans;
    return ans;
}

double soupServings(int n) {
    if(n > 4800)
        return 1.0;
    return solve(n, n);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "The probability that A is used up before or with B is: " << soupServings(n) << std::endl;
    return 0;
}