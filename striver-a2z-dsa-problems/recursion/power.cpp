#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    if(n<0)
        return myPow(1/x,-n);
    if(n==0)
        return 1;
    else if(n%2)
        return x * myPow(x, n-1);
    double ans = myPow(x, n/2);
    return  ans * ans;
}
int main(){
    int n;
    double x;
    cout << "x: ";
    cin >> x;
    cout << "n : ";
    cin >> n;
    double ans = myPow(x, n);
    cout << x << " raised to " << n << " is: " << ans << '\n';
    return 0;
}