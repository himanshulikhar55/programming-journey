#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int len = nums.size()-1, lo = 0, hi = len, mid;
    while(lo<hi){
        mid = (hi+lo)/2;
        if(mid%2){
            if(nums[mid] != nums[mid-1]){
                hi = mid-1;
            } else {
                lo = mid + 1;
            }
        }else {
            if(mid < len && nums[mid] == nums[mid+1])
                lo = mid+1;
            else if(mid == len)
                return nums[mid];
            else
                hi = mid;
        }
    }
    return nums[lo];
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans = singleNonDuplicate(arr);
    cout << "The element that occurs only once in the given array is: " << ans << '\n';
    return 0;
}