#include<bits/stdc++.h>
using namespace std;
// void printElements(int a){
//     cout << a << ' ';
// }
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currSum = 0, n = nums.size();
    for(int i=0;i<n;i++){
        currSum += nums[i];
        if(nums[i] > currSum){
            maxSum = max(maxSum, nums[i]);
            currSum = nums[i];
        } else {
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = maxSubArray(arr);
    cout << "The maximal subarray sum is: " << ans << '\n';
    // for_each(arr.begin(), arr.end(), printElements);
    // cout << '\n';
    return 0;
}