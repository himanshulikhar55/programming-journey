#include<bits/stdc++.h>
using namespace std;
/*
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    A subarray is a contiguous non-empty sequence of elements within an array.
    
    Constraints:
    1 <= nums.length <= 2 * 10^4
    -1000 <= nums[i] <= 1000
    -10^7 <= k <= 10^7
*/
//works for both positive and negative
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), prefixSum = 0, ans = 0;
    unordered_map<int, int> subArrSum;
    for(int i=0;i<n;i++){
        prefixSum += nums[i];
        if(prefixSum == k)
            ans++;
        if(subArrSum[prefixSum - k]> 0){
            ans += subArrSum[prefixSum - k];
        }
        //if k is zero, then prefixsum-k (=prefixsum) will be found and give us wrong ans
        subArrSum[prefixSum]++;
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> nums = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cin >> k;
    cout << "The num of subarrays who have sum " << k << " are " << subarraySum(nums, k) << '\n';
}