#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    int lo = 0, hi = n-1, mid;
    int floor, ceil;
    //let's find floor first
    //floor is the largest element which is smaller than or equal to x
    while(lo <= hi){
        mid = (hi+lo)/2;
        if(arr[mid] > x)
            hi = mid-1;
        else if(arr[mid] < x)
            lo = mid+1;
        else
            return {arr[mid], arr[mid]};
    }
    if (arr[mid] < x)
        floor = arr[mid];
    else if (mid > 0 && arr[mid-1] <= x)
        floor = arr[mid-1];
    else
        floor = -1;
    //now ceil
    //ceil is the smallest element which is greater than or equal to x
    if (arr[mid] > x)
        ceil = arr[mid];
    else if (mid < n-1 && arr[mid+1] >=x)
        ceil = arr[mid+1];
    else    
        ceil = -1;
    return {floor, ceil};
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    pair<int,int> ans = getFloorAndCeil(arr, arr.size(), x);
    cout << "The floor and ceil, respectively of " << x << " are: " << ans.first << ' ' << ans.second << '\n';
    return 0;
}