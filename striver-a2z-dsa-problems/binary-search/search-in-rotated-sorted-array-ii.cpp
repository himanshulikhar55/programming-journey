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
int findMaxElePos(vector<int>& nums, int target){
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
//This is the same solution as search-in-rotated-sorted-array-i
//Will update the solution later.
bool search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return -1;
    int ans = -1, maxElePos, len = nums.size()-1;
    //Let us find the position about which it is rotated first
    //It is guarunteed that the array is rotated around a pivot
   if(nums[0] != nums[len] && nums[0] <= nums[len]){
        ans = findTarget(nums, target, 0, len);
    }
    else{
        maxElePos = findMaxElePos(nums, target);
        if(target < nums[0] && maxElePos < len)
            ans = findTarget(nums, target, maxElePos+1, len);
        else
            ans = findTarget(nums, target, 0, maxElePos);
    }
    return (ans != -1);
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    if(search(arr, x))
        cout << x << " can be found in the given array\n";
    else
        cout << x << " cannot be found in the given array\n";
    return 0;
}