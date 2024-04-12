#include<bits/stdc++.h>
using namespace std;

void printElement(int i){
    cout << i << ' ';
}

void heapify(int arr[], int n, int i) {
    // Your Code Here
    int childPos = 2*i;
    if(childPos >= n)
        return;
    int leftChild, rightChild;
    leftChild = ((childPos+1) < n) ? arr[childPos+1] : INT_MIN;
    rightChild = ((childPos+2) < n) ? arr[childPos+2] : INT_MIN;
    if(leftChild >= rightChild && leftChild > arr[i]){
        swap(arr[i], arr[childPos+1]);
        heapify(arr, n, childPos+1);
    }
    else if(rightChild >= leftChild && rightChild > arr[i]){
        swap(arr[i], arr[childPos+2]);
        heapify(arr, n, childPos+2);
    }
}

//Function to build a Heap from array.
void buildHeap(int arr[], int n) { 
    // Your Code Here
    int lastInternalNode = (n/2)-1;
    for(int i=lastInternalNode; i>=0; i--){
        heapify(arr, n, i);
    }
}

//Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    //code here
    buildHeap(arr, n);
    // for_each(arr, arr+n, printElement);
    // cout << " BH " << '\n';
    for(int i=n-1;i>0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
        // for_each(arr, arr+n, printElement);
        // cout << " HP " << i << '\n';
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    heapSort(arr, n);
    for_each(arr, arr+n, printElement);
    cout << '\n';
    return 0;
}