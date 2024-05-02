#include<bits/stdc++.h>
using namespace std;
/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this
    place are *arranged in a circle*. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security
    system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without
    alerting the police.

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/

int rob(vector<int>& nums) {
    int len = nums.size();
    if(len<2)
        return nums[0];
    vector<int> maxAmt1 = vector<int>(len);
    vector<int> maxAmt2 = vector<int>(len);
    //rob the 1st house, skip the last house
    maxAmt1[0] = nums[0];
    maxAmt1[1] = max(nums[0], nums[1]);
    for(int i=2; i<len-1;i++){
        maxAmt1[i] = max(maxAmt1[i-1],//dont rob this house
                           maxAmt1[i-2]+nums[i]);//rob this house
    }
    //skip the 1st house, rob the last house 
    maxAmt2[1] = nums[1];
    if(len<3)
        return max(maxAmt1[len-2], maxAmt2[len-1]);
    maxAmt2[2] = max(nums[1], nums[2]);
    for(int i=3; i<len;i++){
        maxAmt2[i] = max(maxAmt2[i-1],//dont rob this house
                           maxAmt2[i-2]+nums[i]);//rob this house
    }
    return max(maxAmt1[len-2], maxAmt2[len-1]);
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