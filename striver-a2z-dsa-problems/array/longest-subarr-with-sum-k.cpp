#include<bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[],  int n, int k) { 
    int start = 0, end = 0, maxLen = 0, currSum = 0;
    while(end < n){
        currSum += arr[end];
        while(start <= end && currSum > k){
            currSum -= arr[start];
            start++;
        }
        if(currSum == k){
            maxLen = max(maxLen, end-start+1);
        }
        ++end;
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