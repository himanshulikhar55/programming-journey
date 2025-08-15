/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique
values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1

Constraints:

    1 <= n <= 19
*/
#include <bits/stdc++.h>

std::vector<int> dp = std::vector<int>(20, -1);

int numTrees(int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    int sum = 0;
    if (dp[n] != -1)
        return dp[n];
    for(int i=0;i<n;i++) {
        int left = numTrees(i);
        int right = numTrees(n - i - 1);
        if(left && right)
            sum += left * right;
        else
            sum += left + right;
    }
    dp[n] = sum;
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << numTrees(n) << std::endl;
    return 0;
}