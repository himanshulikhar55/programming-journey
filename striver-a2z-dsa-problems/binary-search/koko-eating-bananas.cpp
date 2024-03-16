#include<bits/stdc++.h>
using namespace std;
bool canEatAtThisRate(vector<int> &piles, int rate, int hours){
    long int time=0, n=piles.size();
    for(int i=0;i<n;i++){
        if(piles[i]%rate)
            time += (piles[i]/rate) + 1;
        else
            time += (piles[i]/rate);
    }
    if(time <= hours)
        return true;
    return false;
}
int minEatingSpeed(vector<int>& piles, int h) {
    sort(piles.begin(), piles.end());
    int n = piles.size();
    int lo = 1, hi = piles[n-1], mid, ans=INT_MAX;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(canEatAtThisRate(piles, mid, h)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    if(lo<ans && canEatAtThisRate(piles, lo, h))
        return lo;
    return ans;
}
int main(){
    int n, h;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> h;
    int ans = minEatingSpeed(arr, h);
    cout << "The min eating speed for koko can eat all the bananas in " << h << " hours is: " << ans << '\n';
    return 0;
}