/*
You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

    The division operator '/' represents real division, not integer division.
        For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
        For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
    You cannot concatenate numbers together
        For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.

Return true if you can get such expression that evaluates to 24, and false otherwise.

 

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24

Example 2:

Input: cards = [1,2,1,2]
Output: false

 

Constraints:
    cards.length == 4
    1 <= cards[i] <= 9
*/

#include <bits/stdc++.h>

char op[4] = {'+','-','/','*'};
bool isPossible = false;

void checkPossible(std::vector<double> &ans) {
    for(double i : ans) {
        if(i == 24)
            isPossible = true;
    }
}

std::vector<double> putParanAndEval(std::string str) {
    int n = str.size();
    std::vector<double> ans, left, right;
    for(int i=0;i<n;i++) {
        if(str[i] == '+' || str[i] == '-' ||
           str[i] == '*') {
            left = putParanAndEval(str.substr(0, i));
            right = putParanAndEval(str.substr(i+1));
            for(int j=0;j<left.size();j++) {
                for(int k=0;k<right.size();k++) {
                    if(str[i] == '+')
                        ans.push_back(left[j] + right[k]);
                    else if(str[i] == '-')
                        ans.push_back(left[j] - right[k]);
                    else if(str[i] == '/')
                        ans.push_back(left[j] / right[k]);
                    else
                        ans.push_back(left[j] * right[k]);
                }
            }
        }
    }
    if(ans.size() == 0)
        ans.push_back(std::atoi(str.c_str()));
    return ans;
}

std::vector<std::string> genExpr(std::vector<int> &cards, int pos) {
    std::vector<std::string> ans;
    if(pos == cards.size())
        return ans;
    std::string currNum = std::to_string(cards[pos]);
    std::vector<std::string> rightExpr = genExpr(cards, pos+1);
    for(int i=0;i<4;i++) {
        for(int j=0;j<rightExpr.size();j++) {
            ans.push_back(currNum + op[i] + rightExpr[j]);
        }
    }
    if(ans.size() == 0) {
        ans.push_back(currNum);
    }
    return ans;
}

bool genPossWaysAndEval(std::vector<int> &cards) {
    std::vector<std::string> possExpr = genExpr(cards, 0);
    
    for(std::string &str : possExpr) {
        std::vector<double> ans = putParanAndEval(str);
        checkPossible(ans);
        if(isPossible)
            return true;
    }
    // for(std::string &str : possExpr)
    //     std::cout << str << ", ";
    // std::cout << std::endl;
    return false;;
}

bool judgePoint24(std::vector<int>& cards) {
    return genPossWaysAndEval(cards);
}

int main() {
    std::vector<int> cards(4);
    for(int i=0;i<4;i++)
        std::cin >> cards[i];
    if(judgePoint24(cards))
        std::cout << "Yay! It is possible!" << std::endl;
    else
        std::cout << "Oh no! It is not possible :(" << std::endl;
    return 0;
}