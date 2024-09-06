#include<bits/stdc++.h>
using namespace std;
long long nthPower(int n, int pow){
    if(pow == 0)
        return 1;
    else if(pow%2)
        return n * nthPower(n,pow-1);
    return 
}
int NthRoot(int n, int m) {
    if(n==1)
        return m;
    
}
int main(){
    int n, m;
    cin >> n >> m;
    int ans = NthRoot(n, m);
    cout << "The " << n << "th square root of " << m << " is: " << ans << '\n';
    return 0;
}