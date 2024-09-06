#include <bits/stdc++.h>
using namespace std ;

void sumPossible(vector<int> &arr, int sum, vector<int> &ans, int start, bool *found){
    if(sum == 0 && !(*found)){
        *found = true;
        ans.push_back(1);
        return;
    } else if(start == arr.size())
        return;
    else{
        //take the element at start
        sumPossible(arr, sum-arr[start], ans, start+1, found);
        //dont take the element at start
        sumPossible(arr, sum, ans, start+1, found);
    }
}

void findSubsetWithSum(vector<vector<int>> &sets, vector<int> &ans){
    int len = sets.size();
    for(int i=0;i<len;i++){
        bool found = false;
        sumPossible(sets[i], sets[i][0], ans, 1, &found);
        if(ans.size()!=i+1)
            ans.push_back(0);
    }
}

int main () {
    int n, temp = 0;
    cin >> n;
    vector<vector<int>> sets(n);
    for(int i=0;i<n;i++){
        while(true){
            cin >> temp;
            if(temp == -1)
                break;
            sets[i].push_back(temp);
        }
        temp = 0;
    }
    vector<int> ans;
    findSubsetWithSum(sets, ans);
    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';
    cout << '\n';
}