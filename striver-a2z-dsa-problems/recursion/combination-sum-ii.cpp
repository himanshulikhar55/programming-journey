/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/
#include<bits/stdc++.h>
using namespace std;
void findCombinations(vector<int> &candidates, int target, int currIdx, set<vector<int>> &ans, vector<int> &currCombination){
    //if candidates[currIdx] < target, we either use it in the combination or not.
    if(currIdx < candidates.size()){
        if(candidates[currIdx] <= target){
            currCombination.push_back(candidates[currIdx]);
            if(target == candidates[currIdx]){
                vector<int> temp = vector<int>(currCombination);
                sort(temp.begin(), temp.end());
                ans.insert(temp);
                
            }
            //used it
            findCombinations(candidates, target-candidates[currIdx], currIdx+1, ans, currCombination);
            //did not use it
            currCombination.pop_back();
            findCombinations(candidates, target, currIdx+1, ans, currCombination);
        } else {
            findCombinations(candidates, target, currIdx+1, ans, currCombination);
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    set<vector<int>> ans;
    vector<vector<int>> combination;
    vector<int> currCombination;
    findCombinations(candidates, target, 0, ans, currCombination);
    set<vector<int>>::iterator it= ans.begin();
    for(;it!=ans.end();it++)
        combination.push_back(*it);
    return combination;
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