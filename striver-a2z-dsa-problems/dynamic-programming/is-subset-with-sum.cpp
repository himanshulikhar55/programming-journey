#include<iostream>
#include<stdlib.h>
using namespace std;
bool isSubsetSum(int *arr, int sum, int n){
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
    cout << "Enter the subset sum: ";
    cin >> sum;
    if(isSubsetSum(arr, sum, n))
        cout << "A subset with sum " << sum << " is present\n";
    else
        cout << "A subset with sum " << sum << " is not present\n";
    return 0;
}