
#include<bits/stdc++.h>
using namespace std;
bool possToPlaceCows(vector<int> &stalls, int k, int dist){
    int distBetnTwoCows=0, n=stalls.size(), lastCowPos = stalls[0];
    --k;
    for(int i=1;i<n;i++){
        distBetnTwoCows = stalls[i]-lastCowPos;
        if(distBetnTwoCows >= dist){
            --k;
            if(k==0)
                break;
            lastCowPos = stalls[i];
        }
    }
    if(k)
        return false;
    return true;
}
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int len = stalls.size(), lo = 0, hi = stalls[len-1] - stalls[0], dist;
    while(lo<hi){
        dist = (hi+lo)/2;
        if(possToPlaceCows(stalls, k, dist))
            lo = dist+1;
        else
            hi = dist-1;
    }
    if(possToPlaceCows(stalls, k, lo))
        return lo;
    return lo-1;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    int ans = aggressiveCows(arr, k);
    cout << "The maximum possible min distance between " << k << " cows is: " << ans << '\n';
    return 0;
}