#include<bits/stdc++.h>
using namespace std;
int count(vector<int>& arr, int n, int x) {
    int lo = 0, hi = n-1, mid, left;
    while(lo<hi){
        mid = (hi+lo)/2;
        if(arr[mid] < x)
            lo = mid+1;
        else if(arr[mid] > x)
            hi = mid-1;
        else
            hi = mid;
    }
    if(arr[lo] != x)
        return 0;
    left = lo, lo = 0, hi = n-1;
    while(lo<hi){
        mid = (hi+lo)/2;
        if(arr[mid] <= x)
            lo = mid+1;
        else
            hi = mid-1;
    }
    if(arr[lo]!=x)
        return lo-left;
    return lo-left+1;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    int ans = count(arr, n, x);
    cout << "The number of occurances of " << x << " is: " << ans << '\n';
    return 0;
}