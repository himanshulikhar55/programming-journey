#include<iostream>
#include<stdlib.h>
using namespace std;
int uniquePaths(int m, int n){
    int **dp = (int **)malloc(sizeof(int *) * m);
    for(int i=0;i<m;i++)
        dp[i] = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<m;i++)
        dp[i][0] = 1;
    for(int i=0;i<n;i++)
        dp[0][i] = 1;
    for(int row=1;row<m;row++){
        for(int col=1;col<n;col++){
            dp[row][col] = dp[row][col-1]+dp[row-1][col];
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m, n;
    // cout << "Enter the number of days: ";
    cin >> m >> n;
    cout << "The number of unique paths is: " << uniquePaths(m, n) << '\n';
    // cout << "Enter the pts:\n";
}