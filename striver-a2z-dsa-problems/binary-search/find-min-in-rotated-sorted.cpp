#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int len = nums.size()-1, lo = 0, hi = len, mid;
    if(nums[0] <= nums[len]){
        return nums[0];
    }
    while(lo<hi){
        mid=(lo+hi)/2;
        if(nums[mid]>nums[mid+1])
            return nums[mid+1];
        else if(nums[mid]<nums[0])
            hi = mid-1;
        else
            lo = mid+1;
    }
    return nums[lo+1];
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans = findMin(arr);
    cout << ans << " is the smallest element in the given array.\n";
    return 0;
}