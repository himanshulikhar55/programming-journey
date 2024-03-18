#include<bits/stdc++.h>
using namespace std;
int calcDivSum(vector<int> &nums, int divisor){
    long int divSum=0, n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]%divisor)
            divSum += (nums[i]/divisor) + 1;
        else
            divSum += (nums[i]/divisor);
    }
    return divSum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int len = nums.size(), lo = 1, hi = nums[0], mid, divSum;
    for(int i : nums){
        hi = max(i, hi);
    }
    while(lo<hi){
        mid = (lo+hi)/2;
        divSum = calcDivSum(nums, mid);
        if(divSum > threshold)
            lo = mid+1;
        else
            hi = mid-1;
    }
    if(calcDivSum(nums, lo) <= threshold)
        return lo;
    return lo+1;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    int ans = smallestDivisor(arr, k);
    cout << "The smallest number is: " << ans << '\n';
    return 0;
}