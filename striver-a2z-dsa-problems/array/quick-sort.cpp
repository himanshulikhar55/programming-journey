#include<bits/stdc++.h>
using namespace std;
/*
    pivot is the last ele
    if you want to make middle element the pivot, take it and move it to low and partition from low+1 to high or move it to 
    high and partition from low to high-1
*/
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int idx = high;
    --high;
    while(low <= high){
        while(low <= high && arr[low] < pivot)
            ++low;
        while(low <= high && arr[high] >= pivot)
            --high;
        if(low <= high){
            swap(arr[low],arr[high]);
            ++low;
            --high;
        }
    }
    swap(arr[idx], arr[low]);
    return low;
}
void quickSort(int arr[], int low, int high) {
    if(low < high){
        int pivot = partition(arr, low, high);
        // cout << pivot << '\n';
        quickSort(arr, low, pivot-1);
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