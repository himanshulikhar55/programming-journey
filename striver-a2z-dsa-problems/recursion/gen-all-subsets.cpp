#include<bits/stdc++.h>
using namespace std;
/*
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/
void findAllSubsets(vector<int> arr, int i, vector<vector<int>> &ans, vector<int> &currSubset){
    if(i<arr.size()){
        //include curr element
        currSubset.push_back(arr[i]);
        findAllSubsets(arr, i+1, ans, currSubset);
        //dont include the curr element
        currSubset.pop_back();
        findAllSubsets(arr, i+1, ans, currSubset);
    } else if(i == arr.size()){
        ans.push_back(currSubset);
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    findAllSubsets(nums, 0, ans, temp);
    return ans;
}
void printEle(int i){
    cout << i << ' ';
}
void printElements(vector<int> &arr){
    for_each(arr.begin(), arr.end(), printEle);
    cout << '\n';
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    vector<vector<int>> ans = subsets(arr);
    cout << "All possible subset of the given set are: \n";
    for(vector<int> temp: ans)
        printElements(temp);
    return 0;
}