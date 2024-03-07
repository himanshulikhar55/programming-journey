#include<bits/stdc++.h>
using namespace std;
// void printElements(int a){
//     cout << a << ' ';
// }
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    int startPos = 0, endPos = 0, ans = 0, n = arr.size(), sumTillNow = 0;
    while(endPos < n){
        sumTillNow += arr[endPos];
        if(sumTillNow == k){
            ans = max(ans, endPos-startPos+1);
        } else if(sumTillNow > k){
            while(startPos<=endPos && sumTillNow > k){
                sumTillNow -= arr[startPos];
                startPos++;
            }
            if(sumTillNow == k){
                ans = max(ans, endPos-startPos+1);
            }
        }
        ++endPos;
    }
    return ans;
}
int main(){
    int n, temp, k;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> k;
    int ans = longestSubarrayWithSumK(arr, k);
    cout << "The maximal len subarray with sum " << k << " is: " << ans << '\n';
    // for_each(arr.begin(), arr.end(), printElements);
    // cout << '\n';
    return 0;
}