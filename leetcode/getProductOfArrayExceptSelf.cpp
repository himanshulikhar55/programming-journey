#include<bits/stdc++.h>
using namespace std;
int prodArr[100001];
int *getProductArrayExceptSelf(int *arr, int n) {
    int MOD = 1000000007, prodOfArrEle = 1, foundZero = 0, foundZeroAt = 0;
    if(n<2){
        prodArr[0] = 0;
        return prodArr;
    }
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            foundZero = 1;
            foundZeroAt = i;
            for(i = i+1;i<n;i++){
                prodOfArrEle = (prodOfArrEle * arr[i]) % MOD;
            }
            break;
        }
        prodOfArrEle = (prodOfArrEle * arr[i]) % MOD;
        cout << prodOfArrEle <<' ';
    }
    for(int i=0;i<n;i++){
        cout << foundZero << '\n';
        if(foundZero){
            if(i==foundZeroAt){
                prodArr[i] = prodOfArrEle;
            } else {
                prodArr[i] = 0;
            }
        } else {
            prodArr[i] = prodOfArrEle / arr[i];
        }
    }
    return prodArr;
}
/*
5
5
1 2 3 4 5
1
0
0
2
5 5
3
0 1 2
*/
int main(){
    int t,n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t--){
        cout << "Enter n: ";
        cin >> n;
        int arr[n];
        cout <<"Enter the array: ";
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int *ans = getProductArrayExceptSelf(arr, n);
        cout << "came here\n";
        for(int i=0;i<n;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}