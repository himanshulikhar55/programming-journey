#include<bits/stdc++.h>
using namespace std;
int findInRotatedSorted(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        if(arr[mid] > arr[mid + 1])
            return mid;
        if(arr[mid] < arr[low])
            return findInRotatedSorted(arr, low, mid-1);
        else if(arr[mid] > arr[high])
            return findInRotatedSorted(arr, mid+1, high);
    }
    return high;
}
int binarySearch(int arr[], int low, int high, int key){
    int mid;
    while(low<high){
        mid = low + (high-low)/2;
        cout << "mid is: " << mid << '\n';
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int low = 0, high = n-1, mid = low + (high-low)/2;
    int pivot = findInRotatedSorted(arr, low, high);
    cout << "pivot is: " << pivot << '\n';
    if(key == arr[pivot])
        return pivot;
    else if(key > arr[pivot])
        return -1;
    else if(key >= arr[low]){
        int pos = binarySearch(arr, low, pivot-1, key);
        if(arr[pos]!=key)
            return -1;
        return pos;
    }
    else{
        int pos = binarySearch(arr, pivot+1, high, key);
        if(arr[pos]!=key)
            return -1;
        return pos;
    }
}
int main(){
    cout << "Enter n: ";
    int n, q, temp, pos;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Enter the number of queries: ";
    cin >> q;
    while(q--){
        cout << "Enter the number you want to search: ";
        cin >> temp;
        pos = search(arr, n, temp);
        if(pos == -1){
            cout << temp << " does not exist in arr\n";
        } else {
            cout << temp << " exists at position: " << pos << '\n';
        }
    }
    return 0;
}