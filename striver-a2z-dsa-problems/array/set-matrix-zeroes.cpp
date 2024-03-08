#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
void printRows(vector<int> a){
    for_each(a.begin(), a.end(), printElements);
    cout << '\n';
}
void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows, columns;
    int m = matrix.size(), n = matrix[0].size(), row, col;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0){
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    set<int>::iterator rowIt, colIt = columns.begin();
    for(rowIt = rows.begin();rowIt!=rows.end();rowIt++){
        row = *rowIt;
        for(int i=0;i<n;i++)
            matrix[row][i] = 0;
    }
    for(colIt = columns.begin();colIt!=columns.end();colIt++){
        col = *colIt;
        for(int i=0;i<m;i++)
            matrix[i][col] = 0;
    }
}
int main(){
    int m, n;
    vector<int> arr;
    vector<vector<int>> matrix;
    cin >> m >> n;
    matrix = vector<vector<int>>(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin >> matrix[i][j];
    }
    setZeroes(matrix);
    cout << "The matrix after setting rows and columns zero: \n";
    for_each(matrix.begin(), matrix.end(), printRows);
    return 0;
}