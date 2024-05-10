#include<bits/stdc++.h>
using namespace std;
//works for both positive and negative
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowNum = 0, colNum = 0;
    vector<int> ans;
    if(matrix.size() == 0)
        return ans;
    int rows = matrix.size()-1, cols = matrix[0].size()-1;
    while(rowNum <= rows && colNum <= cols){
        //going left to right
        for(int i=colNum; i<=cols; i++)
            ans.push_back(matrix[rowNum][i]);
        ++rowNum;
        //going up to down
        for(int i=rowNum; i<=rows; i++)
            ans.push_back(matrix[i][cols]);
        --cols;
        //going right to left
        if (rowNum <= rows) {
            for(int i=cols; i>= colNum; i--)
                ans.push_back(matrix[rows][i]);
            --rows;
        }
        //going down to up
        if(colNum <= cols){
            for(int i=rows; i>= rowNum; i--)
                ans.push_back(matrix[i][colNum]);
            ++colNum;
        }
    }
    return ans;
}
void printInt(int i) {
    cout << i << ' ';
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> matrix[i][j];
    vector<int> ans = spiralOrder(matrix);
    cout << "The spiral traversal of the given matrix is: \n";
    for_each(ans.begin(), ans.end(), printInt);
    cout << '\n';
    return 0;
}