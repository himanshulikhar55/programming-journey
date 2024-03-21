
#include<bits/stdc++.h>
using namespace std;
bool canAllocPages(vector<int> &arr, int k, int pages){
    int pagesAllocToCurr=0, n=arr.size();
    --k;
    for(int i=0;i<n;i++){
        pagesAllocToCurr += arr[i];
        if(pagesAllocToCurr > pages){
            pagesAllocToCurr = arr[i];
            --k;
        }
    }
    return k<0;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;
    int lo = *max_element(arr.begin(), arr.end()), hi = 0, pages;
    for(int i=0;i<n;i++)
        hi += arr[i];
    while(lo<=hi){
        cout << lo << ' ' << hi << '\n';
        pages = (hi+lo)/2;
        if(canAllocPages(arr, m, pages))
            lo = pages+1;
        else
            hi = pages-1;
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
    int ans = findPages(arr, arr.size(), k);
    cout << "The min possible max number of pages assigned to " << k << " students is: " << ans << '\n';
    return 0;
}