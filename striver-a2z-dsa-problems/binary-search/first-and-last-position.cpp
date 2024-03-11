#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() < 1)
        return {-1, -1};
    int lo = 0, hi = nums.size()-1, mid;
    vector<int> ans;
    while(lo<=hi){
        mid = (hi+lo)/2;
        if(nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if(nums[mid] == target)
        ans.push_back(mid);
    else if(mid < nums.size()-1 && nums[mid+1] == target)
        ans.push_back(mid+1);
    else
        return {-1, -1};
    lo = 0, hi = nums.size()-1;
    while(lo<=hi){
        mid = (hi+lo)/2;
        if(nums[mid] <= target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << mid << '\n';
    if(nums[mid] == target)
        ans.push_back(mid);
    else if(nums[mid-1] == target)
        ans.push_back(mid-1);
    return ans;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    vector<int> ans = searchRange(arr, x);
    cout << "The start and end position of " << x << " are: " << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}