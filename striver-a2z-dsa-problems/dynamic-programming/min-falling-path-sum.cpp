#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int minFallingPathSum(int **arr, int m, int n) {
    int **dp = (int **)malloc(sizeof(int *) * m);
    for(int i=0;i<m;i++)
        dp[i] = (int *)malloc(sizeof(int) * n);
    int min_sum = INT_MAX, curr_col_min = INT_MAX;
    int last_row, curr_col;
    for(int i=0;i<n;i++)
        dp[0][i] = arr[0][i];
    for(int row=1;row<m;row++){
        for(int col=0;col<n;col++){
            curr_col_min = INT_MAX;
            for(int idx=-1;idx<=1;idx++){
                last_row = row-1, curr_col = col+idx;
                if(curr_col>=0 && curr_col<n){
                    curr_col_min = min(curr_col_min, dp[last_row][curr_col]);
                }
            }
            dp[row][col] = arr[row][col]+curr_col_min;
        }
    }
    for(int i=0;i<n;i++)
        min_sum = min(min_sum, dp[m-1][i]);
    return min_sum;
}
// int minFallingPathSum(vector<vector<int>>& matrix) {
    
// }
int main(){
    int m, n;
    // cout << "Enter the number of days: ";
    cin >> m >> n;
    int **arr = (int **)malloc(sizeof(int *) * m);
    for(int i=0;i<m;i++)
        arr[i] = (int *)malloc(sizeof(int) * n);
    for(int row=0;row<m;row++)
        for(int col=0;col<n;col++)
            cin >> arr[row][col];
    cout << "The minimum sum falling path is: " << minFallingPathSum(arr, m, n) << '\n';
    return 0;
}