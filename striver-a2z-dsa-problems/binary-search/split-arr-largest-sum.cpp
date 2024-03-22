
#include<bits/stdc++.h>
using namespace std;
bool sumPossible(vector<int> &arr, int numSubArr, int sum){
    int currSum=0, n=arr.size();
    --numSubArr;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum > sum){
            --numSubArr;
            currSum = arr[i];
        }
    }
    return numSubArr>=0;
}
int splitArray(vector<int>& nums, int k) {
    //no need to check k < nums.size() since it is given in the question itself
    int n = nums.size(), lo = *max_element(nums.begin(), nums.end()), hi=0, sum;
    for(int i=0;i<n;i++)
        hi += nums[i];
    while(lo<=hi){
        sum = (hi+lo)/2;
        cout << lo << ' ' << sum << ' ' << hi << '\n';
        if(sumPossible(nums, k, sum))
            hi = sum-1;
        else
            lo = sum+1;
    }
    return lo;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    int ans = splitArray(arr, k);
    cout << "The  minimized largest sum of the split of array in " << k << " subarrays is: " << ans << '\n';
    return 0;
}