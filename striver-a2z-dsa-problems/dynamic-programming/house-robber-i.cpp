#include<bits/stdc++.h>
using namespace std;
/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only
    constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically
    contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight
    without alerting the police.

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/
int rob(vector<int>& nums) {
    int len = nums.size();
    if(len < 2)
        return nums[0];
    vector<int> maxAmount = vector<int>(len+1);
    maxAmount[0] = 0;
    maxAmount[1] = nums[0];
    for(int i=2;i<=len;i++){
        maxAmount[i] = max(maxAmount[i-1], //dont rob this house
                           maxAmount[i-2] + nums[i-1]);//rob this house
    }
    return maxAmount[len];
}
int main(){
    int n;
    cin >> n;
    vector<int> nums = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "The max amount the robber can rob is: " << rob(nums) << '\n';
    return 0;
}