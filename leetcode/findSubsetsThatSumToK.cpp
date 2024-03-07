#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void helper(vector<int> arr, int n, int k, vector<int> temp, int sum){
    if(n == 0){
        if(sum == k)
            ans.push_back(temp);
        return;
    }
    vector<int> newTemp;
    if(temp.size() == 0){
        helper(arr, n-1, k, newTemp, 0);
        newTemp.push_back(arr[n-1]);
        helper(arr, n-1, k, newTemp, arr[n-1]);
    } else {
        helper(arr, n-1, k, temp, sum);
        // if(sum == k)
        //     ans.push_back(temp);
        temp.push_back(arr[n-1]);
        helper(arr, n-1, k, temp, sum+arr[n-1]);
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    int sum = 0;
    vector<int> temp;
    helper(arr, n, k, temp, 0);
    return ans;
}
int main(){
    int n,k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    findSubsetsThatSumToK(arr, n, k);
    cout << "--------------------PRINTING NOW-----------------------\n";
    for(vector<int> temp : ans){
        for(int i : temp)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}