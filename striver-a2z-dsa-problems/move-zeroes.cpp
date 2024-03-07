#include<bits/stdc++.h>
using namespace std;
void printElem(int i){
    cout << i << ' ';
}
void moveZeroes(vector<int>& nums) {
    int n = nums.size(), numZeroes = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            ++numZeroes;
        } else if(numZeroes && nums[i] != 0) {
            nums[i-numZeroes] = nums[i];
            nums[i] = 0;
        }
    }
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    moveZeroes(arr);
    cout << "After moving the zeroes to the end the array is: \n";
    for_each(arr.begin(), arr.end(), printElem);
    cout << '\n';
    return 0;
}
/*
0 1 0 2 3 4 5
*/