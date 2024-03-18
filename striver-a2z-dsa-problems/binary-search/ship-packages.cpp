#include<bits/stdc++.h>
using namespace std;
int calcDays(vector<int> &weights, int capacity){
    int weightSum=0, n=weights.size(), days=1;
    for(int i=0;i<n;i++){
        weightSum += weights[i];
        if(weightSum >= capacity){
            ++days;
            if(weightSum == capacity)
                weightSum = 0;
            else
                weightSum = weights[i];
        }
    }
    if(weightSum==0)
        return days-1;
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int lo=INT_MIN, hi=0, mid, len=weights.size(), daysReqForWt;
    for(int i=0;i<len;i++){
        hi += weights[i];
        if(lo<weights[i])
            lo = weights[i];
    }
    if(days == 1)
        return hi;
    while(lo<hi){
        mid = (lo+hi)/2;
        daysReqForWt = calcDays(weights, mid);
        if(daysReqForWt <= days)
            hi = mid;
        else if(daysReqForWt > days)
            lo = mid+1;
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
    int ans = shipWithinDays(arr, k);
    cout << "The least weight capacity is: " << ans << '\n';
    return 0;
}