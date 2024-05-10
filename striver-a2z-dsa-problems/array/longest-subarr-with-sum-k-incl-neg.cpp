#include<bits/stdc++.h>
using namespace std;
//works for both positive and negative
int lenOfLongSubarr(int arr[],  int n, int k) { 
    int maxLen = 0, currSum = 0;
    unordered_map<int, int> subArrSum;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum == k)
            maxLen = max(maxLen, i+1);
        //since we need maximum length, we will put in the earliest index
        if(subArrSum.find(currSum) == subArrSum.end())
            subArrSum[currSum] = i;
        if(subArrSum.find(currSum-k) != subArrSum.end())
            maxLen = max(maxLen, i - subArrSum[currSum-k]);
    }
    return maxLen;
}
int main(){
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    cout << "The length of longest subarray with sum " << k << " is " << lenOfLongSubarr(arr, n, k) << '\n';
}