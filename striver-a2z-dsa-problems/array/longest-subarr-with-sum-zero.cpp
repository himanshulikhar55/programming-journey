#include<bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int sumTillNow=0, n = arr.size(), maxLen = INT_MIN;
    unordered_map<int, int> sumTillNowMap;
    for(int i=0;i<n;i++){
        sumTillNow += arr[i];
        if(sumTillNow == 0){
            maxLen = i + 1;
        } else {
            if(sumTillNowMap.find(sumTillNow) != sumTillNowMap.end()){
                maxLen = max(maxLen, i - sumTillNowMap[sumTillNow]);
            } else {
                sumTillNowMap[sumTillNow] = i;
            }
        }
    }
    return max(0, maxLen);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans =  getLongestZeroSumSubarrayLength(arr);
    cout << "The len of longest subarray with sum zero is: " << ans << '\n';
    return 0;
}