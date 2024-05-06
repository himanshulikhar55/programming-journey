#include<bits/stdc++.h>
using namespace std;
/*
    You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

    Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump
    to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

    Constraints:

    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].
*/
int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, curFarthest = 0, len = nums.size();
    //we are guarunteed that we will reach the last index hence we will only check till
    //2nd last element as if the jumps are such that we exactly reach n-1 then the final
    //answer will be one more than we would have wanted because on the last index, we will again update jump but we will have already
    //reached out destination
    for(int i=0;i<len;i++){
        //we will check how far can we go. This will be max of "how far we can go from here" and "how far we can go till now"
        curFarthest = max(curFarthest, nums[i]+i);
        //if we have reached the farthest index we can go right now, we will increment the jump count and update the farthest
        //index we can go
        if(i==curEnd){
            jumps++;
            curEnd = curFarthest;
        }
    }
	return jumps;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "We can reach the last index in minimum of " << jump(nums) << " jumps\n";
    return 0;
}