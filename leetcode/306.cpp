/*
An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the
preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid. 

Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

Constraints:

    1 <= num.length <= 35
    num consists only of digits.
*/
#include<bits/stdc++.h>

/*
This gives TLE
bool check(std::vector<long long> &nums) {
    if(nums.size() < 3)
        return false;
    for(int i=2;i<nums.size();i++) {
        if(nums[i] != nums[i-1] + nums[i-2])
            return false;
    }
    return true;
}

bool helper(std::string s, std::vector<long long> &nums, int start, int len) {
    if(start+len-1 == s.length()-1 || len > 15) {
        std::string n = s.substr(start, len);
        long long num = std::stoll(n);
        if(n != std::to_string(num))
            return false;
        nums.push_back(num);
        if(check(nums))
            return true;
        nums.pop_back();
        return false;
    }
    std::string n = s.substr(start, len);
    long long num = std::stoll(n);
    if(n != std::to_string(num))
        return false;
    nums.push_back(num);
    if(helper(s, nums, start+len, 1))
        return true;
    nums.pop_back();
    return helper(s, nums, start, len+1);
}

bool isAdditiveNumber(std::string num) {
    std::vector<long long> nums;
    return helper(num, nums, 0, 1);
}
*/

bool possible(std::string first, std::string second, std::string rem) {
    if((first.length() > 1 && first[0] == '0') || (second.length() > 1 && second[0] == '0'))
        return false;
    std::string sum = std::to_string(std::stol(first) + std::stol(second));
    if(sum == rem)
        return true;
    if(sum.length() >= rem.length() || sum != rem.substr(0, sum.length()))
        return false;
    return possible(second, sum, rem.substr(sum.length()));
}

bool isAdditiveNumber(std::string num) {
    for(int i=1;i<=num.size()/2;i++) {
        for(int j=1;j<(num.size()-1)/2;j++) {
            if(possible(num.substr(0, i), num.substr(i,j), num.substr(i+j)))
                return true;
        }
    }
    return false;
}

int main() {
    std::string s;
    std::cin >> s;
    if(isAdditiveNumber(s))
        std::cout << "Yes it is an additive number!" << std::endl;
    else
        std::cout << "Oh no! It is NOT an additive number!" << std::endl;
    return 0;
}