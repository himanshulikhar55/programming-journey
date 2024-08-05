#include<iostream>
#include<stdlib.h>
using namespace std;
int find_max_pts(int **arr, int n, int ** dp, int curr_act_idx, int day){
    if(day == n){
        return 0;
    }
    if(dp[day][curr_act_idx]!=-1)
        return dp[day][curr_act_idx];
    int max_pts = 0;
    for(int i=0;i<3;i++){
        if(i != curr_act_idx){
            max_pts = max(max_pts, find_max_pts(arr, n, dp, i, day+1));
        }
    }
    dp[day][curr_act_idx] = arr[day][curr_act_idx] + max_pts;
    return dp[day][curr_act_idx];
}
//mostly stackoverflow on input of size 100000
// int maximumPoints(int **arr, int n) {
//     int **dp = (int **)malloc(sizeof(int*) * n);
//     for(int i=0;i<n;i++)
//         dp[i] = (int *)malloc(sizeof(int) * 3);
//     for(int i=0;i<n;i++)
//         for(int j=0;j<3;j++)
//             dp[i][j] = -1;
//     int max_pts = 0;
//     for(int i=0;i<3;i++){
//         max_pts = max(max_pts, find_max_pts(arr, n, dp, i, 0));
//     }
//     return max_pts;
// }
int maximumPoints(int **arr, int n) {
    int **dp = (int **)malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++)
        dp[i] = (int *)malloc(sizeof(int) * 3);
    for(int i=0;i<3;i++)
        dp[n-1][i] = arr[n-1][i];
    for(int day=n-2;day>=0;day--){
        for(int last_act_idx=0;last_act_idx<3;last_act_idx++){
            int max_pts = 0;
            for(int curr_act_idx=0;curr_act_idx<3;curr_act_idx++){
                if(curr_act_idx != last_act_idx){
                    max_pts = max(max_pts, dp[day+1][curr_act_idx]);
                }
            }
            dp[day][last_act_idx] = arr[day][last_act_idx] + max_pts;
        }
    }
    int max_pts = 0;
    for(int i=0;i<3;i++){
        max_pts = max(max_pts, dp[0][i]);
    }
    return max_pts;
}
int main(){
    int n;
    // cout << "Enter the number of days: ";
    cin >> n;
    // cout << "Enter the pts:\n";
    int **arr = (int **)malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++)
        arr[i] = (int *)malloc(sizeof(int) * 3);
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin >> arr[i][j];
    cout << maximumPoints(arr, n);
}