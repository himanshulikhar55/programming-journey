#include<bits/stdc++.h>
using namespace std;
/*
    You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents
    your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

    Constraints:

    1 <= nums.length <= 10^4
    0 <= nums[i] <= 10^5
*/
bool canJump(vector<int>& nums) {
    if(nums.size() < 2)
        return true;
    int distToJump=1, len = nums.size();
    for(int i=len-2; i>=0; i--){
        if(nums[i] >= distToJump){
            distToJump = 1;
        } else {
            distToJump++;
        }
    }
    return distToJump <= nums[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    if(canJump(nums))
        cout << "Yes I can reach the last index\n";
    else
        cout << "No I cannot reach the last index\n";
    return 0;
}