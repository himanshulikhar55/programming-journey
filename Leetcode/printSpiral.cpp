#include <bits/stdc++.h> 
using namespace std;
vector<int> spiralPathMatrix(vector<vector<int>> &matrix, int n, int m) 
{
    // Write your code here.
    int rowStart = 0, rowEnd = n-1, i = 0, j = 0;
    int colStart = 0, colEnd = m-1;
    vector<int> ans;
    while(rowStart <= rowEnd && colStart <= colEnd){
        for(j=colStart;j<=colEnd;j++){
            ans.push_back(matrix[rowStart][j]);
        }
        rowStart++;
        for(i=rowStart;i<=rowEnd;i++)
            ans.push_back(matrix[i][colEnd]);
        colEnd--;
        if(rowStart <= rowEnd){
            for(j=colEnd;j>=colStart;j--)
                ans.push_back(matrix[rowEnd][j]);
            rowEnd--;
        }
        if(colStart <= colEnd){
            for(i=rowEnd;i>=rowStart;i--)
                ans.push_back(matrix[i][colStart]);
            colStart++;
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> arr;
    arr = spiralPathMatrix(matrix, n, m);
    for(int i : arr)
        cout << i << ' ';
    cout << '\n';
    return 0;
}