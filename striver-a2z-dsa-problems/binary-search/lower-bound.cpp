#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int lo = 0, hi = n-1, mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(arr[mid] >= x)
            hi = mid-1;
        else
            lo = mid+1;
    }
    if(arr[mid] >= x)
        return mid;
    else if (mid < n-1 && arr[mid+1] >= x)
        return mid+1;
    else
        return n;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    int ans =  lowerBound(arr, arr.size(), x);
    cout << "The lower bound of " << x << " is: " << ans << '\n';
    return 0;
}