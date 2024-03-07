#include<bits/stdc++.h>
using namespace std;
void printElem(int i){
    cout << i << ' ';
}
void rotate(vector<int>& nums, int k) {
    if(k==0)
        return;
    vector<int> copy_arr = vector<int>(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0;i<n;i++){
        nums[(i+k)%n] = copy_arr[i];
    }
}
int main(){
    int n, temp, k;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> k;
    rotate(arr, k);
    cout << "After rotating the array " << k << " steps,the array: \n";
    for_each(arr.begin(), arr.end(), printElem);
    cout << '\n';
    return 0;
}
/*
5 4 2 9 7 6 1
*/