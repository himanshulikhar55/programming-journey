#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    //since we are already checking indices 0 & len-1
    int lo = 1, hi = nums.size()-2, mid;
    if(nums[0]>nums[1])
        return 0;
    else if(nums[hi+1]>nums[hi])
        return hi+1;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        else if(mid > 0 && nums[mid] > nums[mid-1])
            lo = mid+1;
        else
            hi = mid-1;
    }
    return lo;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans = findPeakElement(arr);
    cout << "One of the peaks of the array is: " << ans << '\n';
    return 0;
}