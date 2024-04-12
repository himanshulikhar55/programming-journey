#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
        // Your code here
        int left=l, right=m+1, idx=0, len=r-l+1;
        int tempArr[len];
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]){
                tempArr[idx]=arr[left];
                ++left;
            }
            else{
                tempArr[idx]=arr[right];
                ++right;
            }
            ++idx;
        }
        while(left<=m){
            tempArr[idx]=arr[left];
            ++left;
            ++idx;
        }
        while(right<=r){
            tempArr[idx]=arr[right];
            ++right;
            ++idx;
        }
        idx=0;
        for(int i=l;i<=r;++i, ++idx){
            arr[i] = tempArr[idx];
        }
}
void mergeSort(int arr[], int l, int r)
{
    //code here
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}
void printElement(int i){
    cout << i << ' ';
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for_each(arr, arr+n, printElement);
    cout << '\n';
    return 0;
}