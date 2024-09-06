#include<iostream>
#include<stdlib.h>
using namespace std;

#define MOD 1000000007

int perfectSum(int arr[], int n, int sum){
    int **dp = (int **)malloc(sizeof(int *) * (n+1));
    for(int i=0;i<=n;i++)
        dp[i] = (int *)malloc(sizeof(int) * (sum+1));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
            dp[i][j] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int curr_sum=0;curr_sum<=sum;curr_sum++){
            if(arr[i-1] <= curr_sum)
                dp[i][curr_sum] = dp[i-1][curr_sum-arr[i-1]] + dp[i-1][curr_sum];
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
    cout << "Enter the subset sum: ";
    cin >> sum;
    cout << "The number of subsets with given sum " << sum << " are: " << perfectSum(arr, n, sum) << '\n';
    return 0;
}