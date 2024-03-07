#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    int startPos = 0, endPos = 0, ans = 0, len = arr.size(), sumTillNow = 0;
    while(endPos < len){
        sumTillNow += arr[endPos];
        if(sumTillNow > k){
            while(sumTillNow > k){
                sumTillNow -= arr[startPos];
                ++startPos;
            }
            if(sumTillNow == k)
                ans = max(ans, endPos - startPos + 1);
        } else if(sumTillNow == k) {
            ans = max(ans, endPos - startPos + 1);
        }
        ++endPos;
    }
    return ans;
}
int main(){
    int n, temp;
    long long k;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> k;
    int ans = longestSubarrayWithSumK(arr, k);
    cout << "The largest subarray with sum " << k << " is " << ans << '\n';
    return 0;
}