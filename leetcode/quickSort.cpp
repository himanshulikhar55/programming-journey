#include <bits/stdc++.h> 
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int low, int high, vector<int> &arr){
    if(low < high){
        int lowPos = low, pivot = arr[high];
        for(int i=low;i<=high-1;i++){
          if (arr[i] < pivot) {
            swap(&arr[lowPos], &arr[i]);
            lowPos++;
          }
        }
        swap(&arr[lowPos], &arr[high]);
        return lowPos;
    }
    return low;
}
void quickSort(int low, int high, vector<int> &arr){
    if (low < high) {
        int pivotIndex = partition(low, high, arr);
        quickSort(low, pivotIndex - 1, arr);
        quickSort(pivotIndex + 1, high, arr);
    }
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr) {
    // Write your code here.
    int n = arr.size() - 1;
    quickSort(0, n, arr);
    return arr;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    arr = quickSortUsingDutchNationalFlag(arr);
    for(int i : arr){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}