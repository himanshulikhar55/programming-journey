#include <bits/stdc++.h>
using namespace std;
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    // unordered_set<int> numsInSq;
    vector<unordered_set<int>>numsInRow, numsInCol;
    for(int i=0;i<9;i++){
        unordered_set<int> tempRow;
        for(int j=0;j<9;j++){
            if(matrix[i][j] != 0){
                tempRow.insert(matrix[i][j]);
            }
        }
        numsInRow.push_back(tempRow);
    }
    for(int i=0;i<9;i++){
        unordered_set<int> tempCol;
        for(int j=0;j<9;j++){
            if(matrix[i][j] != 0){
                tempCol.insert(matrix[j][i]);
            }
        }
        numsInCol.push_back(tempCol);
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<3;j++){
            
        }
    }
}
int main(){
    int matrix[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> matrix[i][j];
        }
    }
    if(isItSudoku(matrix))
        cout << "Yay! It is a matrix!\n";
    else
        cout << "Oh no! It is not a matrix!\n";
    return 0;
}