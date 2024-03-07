#include <bits/stdc++.h>
using namespace std;
vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> zero, ones;
    int i = 0, temp;
    for(int i : arr){
        temp = i;
        temp = temp >> k-1;
        temp = temp & (0x00000001);
        if(temp == 0)
            zero.push_back(i);
        else
            ones.push_back(i);
    }
    for(i=0;i<zero.size();i++)
        arr[i] = zero[i];
    for(int j=0;j<ones.size();j++)
        arr[i] = ones[j];
    return arr;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sortArrayByKBit(n,k,arr);
    for(int i : arr)
        cout << i << ' ';
    cout << '\n';
    return 0;
}