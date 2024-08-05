#include<iostream>
#include<stdlib.h>
using namespace std;
int uniquePathsWithObstacles(int **arr, int m, int n) {
    if(arr[0][0] == 1)
        return 0;
    int **dp = (int **)malloc(sizeof(int *) * m);
    for(int i=0;i<m;i++)
        dp[i] = (int *)malloc(sizeof(int) * n);
    dp[0][0] = 1;
    for(int i=1;i<m;i++){
        if(arr[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        if(arr[0][i] == 1)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i-1];
    }
    for(int row=1;row<m;row++){
        for(int col=1;col<n;col++){
            if(arr[row][col] == 1)
                dp[row][col] = 0;
            else
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
        }
    }
    return dp[m-1][n-1];
}
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
    cout << "The number of unique paths is: " << uniquePathsWithObstacles(arr, m, n) << '\n';
    // cout << "Enter the pts:\n";
}