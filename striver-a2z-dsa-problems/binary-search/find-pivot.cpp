#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &nums){
    int len = nums.size()-1, lo = 0, hi = len, mid;
    if(nums[0] <= nums[len]){
        return 0;
    }
    while(lo<hi){
        mid=(lo+hi)/2;
        if(nums[mid]>nums[mid+1])
            return mid+1;
        else if(nums[mid]<nums[0])
            hi = mid-1;
        else
            lo = mid+1;
    }
    return lo+1;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans = findKRotation(arr);
    cout << "For the given array, the pivot index is: " << ans << '\n';
    return 0;
}