#include<bits/stdc++.h>
using namespace std;
int power(int n, int r){
    if(n==0)
        return 1;
    else if(n == 1)
        return r;
    int num = power(n/2, r);
    if(n%2)
        return (r * num * num)%1000000007;
    return (num * num)%1000000007;
}
int nthTermOfGP(int N, int A, int R) {
    // Write your code here.
    if(N == 1)
        return A;
    return (A * power(N-1, R))%1000000007;
}
int main(){
    int a,n,r;
    cin >> a >> n >> r;
    int ans = nthTermOfGP(a,n,r);
    cout << "nth term is: " << ans << '\n';
}