#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid;
    while(lo<=hi){
        mid = (hi+lo)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if(nums[mid] < target)
        return mid+1;
    else
        return mid;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    int ans =  searchInsert(arr, x);
    cout << "The position where " << x << " should be inserted is: " << ans << '\n';
    return 0;
}