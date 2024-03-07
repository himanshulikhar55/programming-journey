#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
int X,Y;
void findPaths(vector<vector<int>> arr, int x, int y, string moves, vector<vector<bool>> vxisited){
    if(x == X && y == Y){
        ans.push_back(moves);
        return;
    }
    visited[x][y] = true;
    if(x < X && arr[x+1][y] == 1 && !visited[x+1][y]){
        findPaths(arr, x+1, y, moves+"D", visited);
    }
    if(x > 0 && arr[x-1][y] == 1 && !visited[x-1][y]){
        findPaths(arr, x-1, y, moves+"U", visited);
    }
    if(y < Y && arr[x][y+1] == 1 && !visited[x][y+1]){
        findPaths(arr, x, y+1, moves+"R", visited);
    }
    if(y > 0 && arr[x][y-1] == 1 && !visited[x][y-1]){
        findPaths(arr, x, y-1, moves+"L", visited);
    }
}
vector<string> findAllPaths( vector<vector<int>> &arr) {
    //    Write your code here.
    if(arr[0][0] == 0)
        return ans;
    X = arr.size()-1, Y = X;
    vector<vector<bool>> visited = vector<vector<bool>>(X+1,vector<bool>(X+1));
    findPaths(arr, 0, 0, "", visited);
    return ans;
}
int main(){
    vector<vector<int>> arr;
    int n;
    cin >> n;
    arr = vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    findAllPaths(arr);
    for(string s : ans)
        cout << s << '\n';
    return 0;
}