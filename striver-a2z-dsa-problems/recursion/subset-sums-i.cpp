/*
    Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.
    Expected Time Complexity: O(2^n)
    Expected Auxiliary Space: O(2^n)
*/
#include<bits/stdc++.h>
using namespace std;
void currSubsetSum(vector<int> arr, int n, int currSum, int currIdx, vector<int> &ans){
    if(currIdx == n){
        ans.push_back(currSum);
        return;
    }
    currSubsetSum(arr, n, currSum, currIdx+1, ans);
    currSubsetSum(arr, n, currSum+arr[currIdx], currIdx+1, ans);
}
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    currSubsetSum(arr, n, 0, 0, ans);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> ans = subsetSums(arr, n);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}