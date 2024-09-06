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
int minDays(vector<int>& bloomDay, int m, int k) {
    if(m*k > bloomDay.size())
        return -1;
    int len = bloomDay.size();
    

}
int main(){
    int n, m, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> m >> k;
    int ans = minDays(arr, m, k);
    if(ans == -1)
        cout << "It is not possible to make bouquets with given data\n";
    else
        cout << "The min number of days in which we can form " << m << " bouquets with" << k << " flowers each is: " << ans << '\n';
    return 0;
}