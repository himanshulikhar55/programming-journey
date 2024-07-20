/*
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.

For Example

'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
1 <= 'N' <= 10^3
1 <= 'A[i]' <= 10^3
1 <= 'K' <= 10^3
Time Limit: 1 sec
*/
#include<bits/stdc++.h>
using namespace std;
bool subsetPresent(int n, int sum, vector<int> &arr, int currSum, int i){
    if(i == n){
        return currSum == sum;
    }
    if(!subsetPresent(n, sum, arr, currSum, i+1))
        return subsetPresent(n, sum, arr, currSum+arr[i], i+1);
    return true;
}
bool isSubsetPresent(int n, int k, vector<int> &arr){
    // Write your code here
    return subsetPresent(n, k, arr, 0, 0);
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    if(isSubsetPresent(n, k, arr))
        cout << "A subset exists with sum " << k << '\n';
    else
        cout << "A subset does not exist with sum " << k << '\n';
    return 0;
}