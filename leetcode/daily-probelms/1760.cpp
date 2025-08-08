/**
 * Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
 */
#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int>& nums, int mid, int maxOperations){
    int operations = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > mid){
            int ops = nums[i]/mid;
            if(nums[i]%mid == 0)
                ops--;
            operations += ops;
        }
        if(operations > maxOperations)
            return false;
    }
    return true;
}
int minimumSize(vector<int>& nums, int maxOperations) {
    int lo = 1, hi = *max_element(nums.begin(), nums.end()), mid, ans;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        if(possible(nums, mid, maxOperations)){
            hi = mid-1;
            ans = mid;
        } else{
            lo = mid+1;
        }
    }
    return ans;
}
int main(){
    int n, maxOperations;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cin >> maxOperations;
    int ans = minimumSize(nums, maxOperations);
    cout << "Answer: " << ans << '\n';
    return 0;
}