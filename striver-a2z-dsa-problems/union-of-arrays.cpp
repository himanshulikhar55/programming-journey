#include<bits/stdc++.h>
using namespace std;
void printElem(int i){
    cout << i << ' ';
}
vector < int > sortedArray(vector < int > arr1, vector < int > arr2) {
    vector<int> ans;
    int n1 = arr1.size(), n2 = arr2.size(), i = 0, j = 0;
    if(n1==n2 && n1 == 0)
        return ans;
    if(n1 == 0)
        ans.push_back(arr2[0]);
    else if(n2 == 0)
        ans.push_back(arr1[0]);
    else{
        if(arr1[0] < arr2[0])
            ans.push_back(arr1[0]);
        else
            ans.push_back(arr2[0]);
    }
    while(i<n1 && j<n2){
        cout << i << ' ' << j << '\n';
        if(arr1[i] < arr2[j]){
            if(ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            ++i;
        } else if(arr1[i] > arr2[j]){
            if(ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            ++j;
        } else {
            if(ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            ++i, ++j;
        }
    }
    while(i<n1){
        if(ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        ++i;
    }
    while(j<n2){
        if(ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        ++j;
    }
    return ans;
}
int main(){
    int n, m, temp;
    vector<int> arr1, arr2;
    cin >> n;
    while(n--){
        cin >> temp;
        arr1.push_back(temp);
    }
    cin >> m;
    while(m--){
        cin >> temp;
        arr2.push_back(temp);
    }
    vector<int> ans = sortedArray(arr1, arr2);
    cout << "After moving the zeroes to the end the array is: \n";
    for_each(ans.begin(), ans.end(), printElem);
    cout << '\n';
    return 0;
}
/*
0 1 0 2 3 4 5
*/