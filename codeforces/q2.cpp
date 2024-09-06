#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        if(l==L){
            if(r == R)
                cout << r-l << '\n';
            else
                cout << min(R, r)-l+1 << "\n";
        } else if(l<L){
            if(r < L)
                cout << 1 << '\n';
            else if(R < r)
                cout << R-L+2 << '\n';
            else if(R==r)
                cout << 1 + R-L << '\n';
            else
                cout << r-L+2 << '\n';
        } else {
            if(R<l)
                cout << 1 << '\n';
            else if(r<R)
                cout << r-l+2 << '\n';
            else if(r==R)
                cout << 1+R-l << '\n';
            else
                cout << R-l+2 << '\n';
        }
    }
    return 0;
}