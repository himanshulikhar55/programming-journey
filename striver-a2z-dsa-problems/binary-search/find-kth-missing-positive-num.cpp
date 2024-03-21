
#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int currPosNum=1, counter=0, n=arr.size();
    for(int i=0;i<n;i++){
        if(currPosNum != arr[i]){
            --k;
            --i;
            if(k==0)
                return currPosNum;
        }
        ++currPosNum;
    }
    while(k){
        ++currPosNum;
        --k;
    }
    return currPosNum-1;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    int ans = findKthPositive(arr, k);
    cout << "The " << k << "st/nd/rd/th missing positive number is: " << ans << '\n';
    return 0;
}