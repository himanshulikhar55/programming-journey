#include<bits/stdc++.h>
using namespace std;
void insert(int arr[], int i) {
    //code here
    if(arr[i-1]<arr[i])
        return;
    int start=0, num = arr[i], pos, temp;
    while(start<i && arr[start]<arr[i]){
        ++start;
    }
    pos=start;
    int prev=arr[start], curr;
    while(start<i){
        curr=arr[start+1];
        arr[start+1] = prev;
        prev=curr;
        ++start;
    }
    arr[pos] = num;
}
//Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n) {
    //code here
    for(int i=1;i<n;i++){
        insert(arr, i);
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
    insertionSort(arr, n);
    for_each(arr, arr+n, printElement);
    cout << '\n';
    return 0;
}