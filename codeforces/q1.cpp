#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr = vector<int>(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        if(n == 2){
            if(arr[0]-arr[1] > 1 || arr[0]-arr[1] < -1)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}