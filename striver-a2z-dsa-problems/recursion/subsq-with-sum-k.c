#include<stdio.h>
#include<string.h>
#define MOD 1000000007
/*
    Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

    Note: Answer can be very large, so, output answer modulo 10^9+7.
    Expected Time Complexity: O(n*sum)
    Expected Auxiliary Space: O(n*sum)
*/
 
//This is a recursion soln
void findSubsets(int arr[], int n, int sum, int currSum, int currIndex, int *ans){
    if(currSum == sum && currIndex == n){
        *ans = ((*ans) + 1) % MOD;
        return;
    } else if(currIndex >= n)
        return;
    findSubsets(arr, n, sum, currSum, currIndex+1, ans);
    findSubsets(arr, n, sum, currSum+arr[currIndex], currIndex+1, ans);
}
int perfectSum(int arr[], int n, int sum){
    int ans = 0;
    findSubsets(arr, n, sum, 0, 0, &ans);
    return ans;
}
int main(){
    int n, sum;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    scanf("%d", &sum);
    printf("The number of subsets with sum equal to %d are %d\n", sum, perfectSum(arr, n, sum));

}