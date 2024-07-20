/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Constraints:
    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
*/
#include<bits/stdc++.h>
using namespace std;
void findCombinations(vector<int> &candidates, int target, int currIdx, vector<vector<int>> &ans, vector<int> currCombination){
    //if candidates[currIdx] < target, we either use it in the combination or not.
    if(currIdx < candidates.size()){
        if(candidates[currIdx] <= target){
            currCombination.push_back(candidates[currIdx]);
            if(target == candidates[currIdx]){
                ans.push_back(currCombination);
            }
            //used it
            findCombinations(candidates, target-candidates[currIdx], currIdx, ans, currCombination);
            //did not use it
            currCombination.pop_back();
            findCombinations(candidates, target, currIdx+1, ans, currCombination);
        } else {
            findCombinations(candidates, target, currIdx+1, ans, currCombination);
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    findCombinations(candidates, target, 0, ans, {});
    return ans;
}
int main(){
    int n, target;
    cin >> n;
    vector<int> candidates = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> candidates[i];
    cin >> target;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for(vector<int> arr : ans){
        for(int i=0;i<arr.size();i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}