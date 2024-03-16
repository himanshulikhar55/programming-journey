#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n){
    if(n < 2)
        return n;
    int lo = 1, hi = n;
    long mid;
    while(lo<=hi){
        mid = (hi+lo)/2;
        if (mid*mid <= n) {
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    return hi;
}

int main(){
    int n;
    cin >> n;
    int ans = floorSqrt(n);
    cout << "The of square root of " << n << " is: " << ans << '\n';
    return 0;
}