#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long int> arr = vector<long int>(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        long int a = 0, b = 0;
        for(int i=0;i<n;i++){
            if(i%2){
                if(arr[i-1]-arr[i] <= k){
                    b += arr[i-1];
                    k -= (arr[i-1]-arr[i]);
                } else {
                    b += arr[i]+k;
                    k = 0;
                }
            }
            else
                a += arr[i];
        }
        cout << a-b << '\n';
    }
    return 0;
}