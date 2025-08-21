/*
A string s is called happy if it satisfies the following conditions:

    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

Constraints:
    0 <= a, b, c <= 100
    a + b + c > 0
*/
#include<bits/stdc++.h>

std::string longestDiverseString(int a, int b, int c) {
    std::priority_queue<std::pair<int, char>> pq;
    if(a)
        pq.push(std::make_pair(a,'a'));
    if(b)
        pq.push(std::make_pair(b,'b'));
    if(c)
        pq.push(std::make_pair(c,'c'));
    std::string longestStr = "";
    std::pair<int, char> temp;
    int rep = 2;
    while(!pq.empty()) {
        std::pair<int, char> top = pq.top();
        pq.pop();
        if(longestStr.length() && top.second == longestStr.back()) {
            if(pq.empty())
                break;
            temp = pq.top();
            pq.pop();
            pq.push(top);
            if(top.first-temp.first >= 1)
                rep = 1;
            else
                rep = std::min(2, temp.first);
            top = temp;
        } else {
            rep = std::min(2, top.first);
        }
        top.first -= rep;
        if(top.first)
            pq.push(top);
        while(rep--)
            longestStr += top.second;
    }
    return longestStr;
}

int main() {
    int a,b,c;
    std::cin >> a >> b >> c;
    std::cout << longestDiverseString(a,b,c) << std::endl;
    return 0;
}