#include <bits/stdc++.h>
using namespace std;

void callFunc(vector<int> &arr){
    vector<int> copy = arr;
    sort(copy.begin(), copy.end());
    for(int i : arr)
        cout << i << ' ';
    cout << '\n';
    for(int i : copy)
        cout << i << ' ';
    cout << '\n';
}

int main(){
    vector<int> arr = {5,47,2,56,77};
    callFunc(arr);
}