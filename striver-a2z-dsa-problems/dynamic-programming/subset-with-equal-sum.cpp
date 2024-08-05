#include<iostream>
#include<stdlib.h>
using namespace std;
bool canPartition(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2)
        return false;
    sum = sum/2;
    bool **dp = (bool **)malloc(sizeof(bool *) * (n+1));
    for(int i=0;i<=n;i++)
        dp[i] = (bool *)malloc(sizeof(bool) * (sum+1));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
            dp[i][j] = false;
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int curr_sum=0;curr_sum<=sum;curr_sum++){
            if(arr[i-1] <= curr_sum)
                dp[i][curr_sum] = dp[i-1][curr_sum-arr[i-1]] || dp[i-1][curr_sum];
            else
                dp[i][curr_sum] = dp[i-1][curr_sum];
        }
    }
    return dp[n][sum];
}
int main(){
    int n, sum;
    cout << "Enter the array size: ";
    cin >> n;
    int *arr = (int *)malloc(sizeof(int ) * n);
    cout << "Enter the array: \n";
    for(int i=0;i<n;i++)
            cin >> arr[i];
    if(canPartition(arr, n))
        cout << "We can partition the arr in two subsets with equal sum";
    else
        cout << "We cannot partition the arr in two subsets with equal sum";
    return 0;
}