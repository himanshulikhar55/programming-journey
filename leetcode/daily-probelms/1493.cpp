/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray. 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints:

    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
*/
#include<bits/stdc++.h>

int longestSubarray(std::vector<int>& nums) {
    bool found = false;
    int n=nums.size(), left = 0, right = 0, zero = 0, ans = 0;
    while(right < n) {
        if(nums[right]) {
            right++;
            ans = std::max(ans, right-left-zero);
        } else {
            found = true;
            if(zero) {
                ans = std::max(ans, right-left-zero);
                while(nums[left] != 0 && left < right)
                    left++;
                left++;
            } else {
                zero++;
            }
            right++;
        }
    }
    if(!found)
        ans--;
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++)
        std::cin >> arr[i];
    std::cout << longestSubarray(arr) << std::endl;
}