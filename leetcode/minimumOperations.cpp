#include<bits/stdc++.h>
using namespace std;
int calcDiv(int a, int b){
    
    int ans=0;
    while(a>0){
        a = a/b;
        ans++;
    }
    cout << ans << '\n';
    return ans;
}
int minimumOperations(int x, int y) {
    // Write your code here.
    if(y>x)
        return 1;
    else if(y==x)
        return 2;
    int ans = INT_MAX, temp = 0;
    for(int i=y;i<=x;i++){
        temp = 0;
        if(i==1)
            continue;
        temp += i-y;
        temp += calcDiv(x,i);
        ans = min(temp,ans);
    }
    return ans;
}
int main(){
    int x,y;
    cin >> x >> y;
    cout << "Minimum number of operations required are: " << minimumOperations(x, y) << '\n';
    return 0;
}