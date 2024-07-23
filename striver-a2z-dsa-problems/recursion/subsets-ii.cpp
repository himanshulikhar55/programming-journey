/*
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
    
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10

*/
#include<bits/stdc++.h>
using namespace std;
void currSubsetSum(vector<int> arr, int n, vector<int> &currSubset, int currIdx, set<vector<int>> &ans){
    if(currIdx == n){
        ans.insert(currSubset);
        return;
    }
    currSubsetSum(arr, n, currSubset, currIdx+1, ans);
    currSubset.push_back(arr[currIdx]);
    currSubsetSum(arr, n, currSubset, currIdx+1, ans);
    currSubset.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int> &arr) {
    set<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());
    currSubsetSum(arr, arr.size(), temp, 0, ans);
    for(vector<int> arr : ans)
        subsets.push_back(arr);
    return subsets;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<vector<int>> ans = subsetsWithDup(arr);
    for(vector<int> arr : ans){
        for(int i=0;i<arr.size();i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}