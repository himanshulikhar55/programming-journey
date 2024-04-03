#include<bits/stdc++.h>
using namespace std;
//pivot is the last ele
int partition (int arr[], int low, int high) {
    int pivot = arr[(high+low)/2];
    while(low<=high){
        while(low<=high && arr[low] < pivot)
            ++low;
        while(low<=high && arr[high] >= pivot)
            --high;
        if(low<=high)
            swap(arr[low], arr[high]);
    }
    return low;
}
void quickSort(int arr[], int low, int high) {
    if(low < high){
        int pivot = partition(arr, low, high);
        // cout << pivot << '\n';
        quickSort(arr, 0, pivot);
        quickSort(arr, pivot+1, high);
    }
}
void printElement(int x){
    cout << x << ' ';
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for_each(arr, &(arr[n]), printElement);
    cout << '\n';
    return 0;
}
/*
Implementation for quick-sort.
*/