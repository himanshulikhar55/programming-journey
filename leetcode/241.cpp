/*
Given a string expression of numbers and operators, return all possible results from computing all the
different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different
results does not exceed 10^4.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

 

Constraints:
    1 <= expression.length <= 20
    expression consists of digits and the operator '+', '-', and '*'.
    All the integer values in the input expression are in the range [0, 99].
    The integer values in the input expression do not have a leading '-' or '+' denoting the sign.


*/

#include<bits/stdc++.h>

std::vector<int> findDiffWaysToCompute(std::string str, std::unordered_map<std::string, std::vector<int>> dp) {
    int n = str.size();
    std::vector<int> ans, left, right;
    for(int i=0;i<n;i++) {
        if(str[i] == '+' || str[i] == '-' ||
           str[i] == '*') {
            std::string leftStr = str.substr(0, i);
            if(dp.find(leftStr) != dp.end())
                left = dp[leftStr];
            else
                left = findDiffWaysToCompute(leftStr, dp);
            std::string rightStr = str.substr(i+1);
            if(dp.find(rightStr) != dp.end())
                right = dp[rightStr];
            else
                right = findDiffWaysToCompute(rightStr, dp);
            for(int j=0;j<left.size();j++) {
                for(int k=0;k<right.size();k++) {
                    if(str[i] == '+')
                        ans.push_back(left[j] + right[k]);
                    else if(str[i] == '-')
                        ans.push_back(left[j] - right[k]);
                    else
                        ans.push_back(left[j] * right[k]);
                }
            }
        }
    }
    if(ans.size() == 0)
        ans.push_back(std::atoi(str.c_str()));
    return dp[str] = ans;
}

std::vector<int> diffWaysToCompute(std::string expression) {
    std::unordered_map<std::string, std::vector<int>> dp;
    return findDiffWaysToCompute(expression, dp);
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> ans = diffWaysToCompute(s);
    for(int i : ans) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}