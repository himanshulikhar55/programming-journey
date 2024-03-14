#include<bits/stdc++.h>
using namespace std;
int findTarget(vector<int>& nums, int target, int lo, int hi){
    int mid;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    if(nums[lo]==target)
        return lo;
    return -1;
}
int findMaxElePos(vector<int>& nums){
    int len = nums.size()-1, lo = 0, hi = len, mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        if(nums[mid]>nums[mid+1])
            return mid;
        else if(nums[mid]<nums[0])
            hi = mid-1;
        else
            lo = mid+1;
    }
    return lo;
}
int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return -1;
    int ans = -1, maxElePos, len = nums.size()-1;
    //let us find the position about which it is rotated first
    if(nums[0] <= nums[len]){
        ans = findTarget(nums, target, 0, len);
    }
    else{
        maxElePos = findMaxElePos(nums);
        if(target < nums[0])
            ans = findTarget(nums, target, maxElePos+1, len);
        else
            ans = findTarget(nums, target, 0, maxElePos);
    }
    
    return ans;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    int ans = search(arr, x);
    cout << x << " can be found at index:" << ans << '\n';
    return 0;
}