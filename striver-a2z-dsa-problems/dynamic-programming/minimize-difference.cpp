#include<iostream>
#include<stdlib.h>
using namespace std;

#define MOD 1000000007
int minimumDifference(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    
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
    cout << "The number of subsets with given sum " << sum << " are: " << minimumDifference(arr, n) << '\n';
    return 0;
}